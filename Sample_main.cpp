
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <glm/glm.hpp>

#include <GL/glew.h>
#include <GL/glut.h>

#include <general/resolution.hpp>

using namespace std;

//Global Variables
int WIDTH = 600; int HEIGHT = 600;
int reswidth, resheight;
//input vector
std::vector<glm::vec2> vertices;
//Buffers
GLuint programID;
GLuint Buffers[1];
GLuint VertexArrayID[2];
bool isCirlce = false;

//Uniforms
GLuint tessID;
int tessLv = 10;

GLuint LoadShaders(const char* vertex_file_path, const char* fragment_file_path, const char* geometry_file_path)
{
	//create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	GLuint GeometryShaderID = glCreateShader(GL_GEOMETRY_SHADER);

	GLint Result = GL_FALSE;
	int InfoLogLength;

	//Read the vertex shader code from the file
	string VertexShaderCode;
	ifstream VertexShaderStream(vertex_file_path, ios::in);
	if(!VertexShaderStream.is_open()){
        printf("Vertex Shader : [%s] Open failed\n", vertex_file_path);
    }
	if(VertexShaderStream.is_open())
	{
		string Line = "";
		while(getline(VertexShaderStream, Line))
			VertexShaderCode += "\n" + Line;
		VertexShaderStream.close();
	}

	//Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	char const* VertexSourcePointer = VertexShaderCode.c_str();
	glShaderSource(VertexShaderID, 1, &VertexSourcePointer, NULL);
	glCompileShader(VertexShaderID);

	//Check Vertex Shader
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength != 0){
	vector<char> VertexShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &VertexShaderErrorMessage[0]);}

	//Read the fragment shader code from the file
	string FragmentShaderCode;
	ifstream FragmentShaderStream(fragment_file_path, ios::in);
	if(FragmentShaderStream.is_open())
	{
		string Line = "";
		while(getline(FragmentShaderStream, Line))
			FragmentShaderCode += "\n" + Line;
		FragmentShaderStream.close();
	}

	//Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	char const* FragmentSourcePointer = FragmentShaderCode.c_str();
	glShaderSource(FragmentShaderID, 1, &FragmentSourcePointer, NULL);
	glCompileShader(FragmentShaderID);

	//Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength != 0){
	vector<char> FragmentShaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &FragmentShaderErrorMessage[0]);
    fprintf(stdout, "%s\n", &FragmentShaderErrorMessage[0]);}

	//Read the Geometry shader code from the file
	string GeometryShaderCode;
	ifstream GeometryShaderStream(geometry_file_path, ios::in);
	if(!GeometryShaderStream.is_open()){
        printf("Geometry Shader : [%s] Open failed\n", geometry_file_path);
    }
	if(GeometryShaderStream.is_open())
	{
		string Line = "";
		while(getline(GeometryShaderStream, Line))
			GeometryShaderCode += "\n" + Line;
		GeometryShaderStream.close();
	}

	//Compile Geometry Shader
	printf("Compiling shader : %s\n", geometry_file_path);
	char const* GeometrySourcePointer = GeometryShaderCode.c_str();
	glShaderSource(GeometryShaderID, 1, &GeometrySourcePointer, NULL);
	glCompileShader(GeometryShaderID);

	//Check Geometry Shader
	glGetShaderiv(GeometryShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(GeometryShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if(InfoLogLength != 0){
	vector<char> GeometryShaderErrorMessage(InfoLogLength);
	glGetShaderInfoLog(GeometryShaderID, InfoLogLength, NULL, &GeometryShaderErrorMessage[0]);
	fprintf(stdout, "%s\n", &GeometryShaderErrorMessage[0]);}


	//Link the program
	fprintf(stdout, "Linking program\n");
    GLuint ProgramID = glCreateProgram();
    glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, GeometryShaderID);
    glAttachShader(ProgramID, FragmentShaderID);
    glLinkProgram(ProgramID);
 
    // Check the program
    glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    vector<char> ProgramErrorMessage( max(InfoLogLength, int(1)) );
    glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
    fprintf(stdout, "%s\n", &ProgramErrorMessage[0]);
 
    glDeleteShader(VertexShaderID);
	glDeleteShader(GeometryShaderID);
    glDeleteShader(FragmentShaderID);
 
    return ProgramID;
}


void renderScene(void)
{
	//printf("%d\n", vertices.size());
	//Clear all pixels
	glClear(GL_COLOR_BUFFER_BIT);
	//Let's draw something here
	glUniform1i(tessID, tessLv);

	//bind and buffer data since data is added on callback function
	//glBindVertexArray(VertexArrayID[0]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);

	//Draw Control Points
	glDrawArrays(GL_LINES_ADJACENCY, 0, vertices.size());
	//glDrawArrays(GL_POINTS, 0, vertices.size());
	//Double buffer
	glutSwapBuffers();
	//glutPostRedisplay();
}

void tess(bool isCircle){
	int iter=1;
	if(isCircle) iter = 4; 
	float dy = vertices[1].y-vertices[0].y;
	float dx = vertices[1].x-vertices[0].x;
	float d = glm::sqrt(dy*dy + dx*dx);
	float theta = atan2(dy, dx);
	for(int i=1; i<=tessLv*iter; i++){
		float theta2 = glm::radians(90.0f/tessLv*i);
		vertices.emplace_back(glm::vec2(vertices[0].x+d*glm::cos(theta+theta2),vertices[0].y+d*glm::sin(theta+theta2)));
	}
}

void reset(){
	glm::vec2 tmp1 = vertices[0];
	glm::vec2 tmp2 = vertices[1];

	vertices.clear();
	vertices.push_back(tmp1);
	vertices.push_back(tmp2);
}

void MouseEvent(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		vertices.push_back(glm::vec2(((float)x/WIDTH-0.5)*2,((float)(-y)/HEIGHT+0.5)*2)); 
		printf("%f %f\n", ((float)x/WIDTH-0.5)*2,((float)(-y)/HEIGHT+0.5)*2);
	}
	if(state == GLUT_DOWN){
		printf("vertex size : %d\n", vertices.size());
	}

}

void KeyboardEvent(int key, int x, int y){
	if(key == GLUT_KEY_RIGHT){
		tessLv += 10;
		tessLv = tessLv > 256 ? 256 : tessLv;
	}else if(key == GLUT_KEY_LEFT){
		tessLv -= 10;
		tessLv = tessLv < 10? 10: tessLv;
	}
	printf("tessellation Level : %d\n", tessLv);
	glutPostRedisplay();
}

void init()
{
    //initilize the glew and check the errors.
    
    GLenum res = glewInit();
    if(res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s' \n", glewGetErrorString(res));
    }
	//select the background color
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_VERTEX_PROGRAM_POINT_SIZE);

}


int main(int argc, char **argv)
{
	//init GLUT and create Window
	//initialize the GLUT
	glutInit(&argc, argv);
	//GLUT_DOUBLE enables double buffering (drawing to a background buffer while the other buffer is displayed)
#ifdef WINDOWS  // 윈도우즈에서 컴파일 할때는 아래를 포함
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
#else
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
#endif
	//These two functions are used to define the position and size of the window. 

    GL_Resolution gl_resolution = GL_Resolution::getResInstance();
    gl_resolution.SetWindowResolution(WIDTH, HEIGHT);
    glm::vec2 dispRes = gl_resolution.GetDisplayResolution();
    glm::vec2 windRes = gl_resolution.GetWindowResolution();

	glutInitWindowPosition((dispRes.x-windRes.x)/2, (dispRes.y-windRes.y)/2);
	glutInitWindowSize(windRes.x, windRes.y);
	//This is used to define the name of the window.
	glutCreateWindow("Computer Graphics Advance : HW1");

	//call initization function
	init();

	//1.
	//Generate VAO
	glGenVertexArrays(2, VertexArrayID);

	//2.useProgramID 
	programID = LoadShaders("VertexShader.txt", "FragmentShader.txt", "GeometryShader.txt");
	glUseProgram(programID);

	//3.Generate VBO & Bind into VAO
	glBindVertexArray(VertexArrayID[0]);
	glGenBuffers(1, &Buffers[0]);
	glBindBuffer(GL_ARRAY_BUFFER, Buffers[0]);
	glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(glm::vec2), &vertices[0], GL_STATIC_DRAW);
	//Link Attrib
	GLuint vertexAttr = glGetAttribLocation(programID, "pos");
	glVertexAttribPointer(vertexAttr, 2, GL_FLOAT, GL_FALSE, 0 ,((void *)0));
	glEnableVertexAttribArray(vertexAttr);
	//Link Uniform
	tessID = glGetUniformLocation(programID, "tessLv");

	//callback Function
	glutDisplayFunc(renderScene);
	glutMouseFunc(MouseEvent);
	glutSpecialFunc(KeyboardEvent);

	//enter GLUT event processing cycle
	glutMainLoop();

	glDeleteVertexArrays(1, VertexArrayID);
	
	return 1;
}

