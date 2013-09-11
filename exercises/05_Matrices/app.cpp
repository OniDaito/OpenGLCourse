/**
* @brief GLFW Window based solution
* @file app.hpp
* @author Benjamin Blundell <oni@section9.co.uk>
* @date 03/07/2012
*
*/

#include "app.hpp"

#include <boost/program_options.hpp>
#include <signal.h>

using namespace std;
using namespace boost;
using namespace boost::assign;
using namespace s9;
using namespace s9::gl;

namespace po = boost::program_options;

unsigned int * handle = new unsigned int[2];

GLuint vao[1];

GLuint mProgram;

GLuint vertexLoc, colorLoc;

// Locations of our two matrices within the shader
GLuint projMatrixLoc, viewMatrixLoc;


// Our Actual Matrices

glm::mat4 projMatrix;
glm::mat4 viewMatrix;


/*
 * Called when the mainloop starts, just once
 */

void BasicApp::init(){
    link(*this);

    createShader();
    createBuffers();

    projMatrix = glm::perspective(55.0, 4.0/3.0, 0.1, 100.0);
    viewMatrix = glm::lookAt(glm::vec3(0,0,5.0), glm::vec3(0.0,0.0,0.0), glm::vec3(0,1.0,0.0));

}

/*
 * Create Shader 
 */

void BasicApp::createShader() {

    // The following are variables we need

    GLuint mVS, mFS;
    
    int isCompiled_VS, isCompiled_FS;
    
    int maxLength;
    int IsLinked;
    char *vertexInfoLog;
    char *fragmentInfoLog;
    char *shaderProgramInfoLog;

    // Create handles for the programs

    mVS = glCreateShader(GL_VERTEX_SHADER);
    mFS = glCreateShader(GL_FRAGMENT_SHADER);   

    // Read in the shaders

    // We alter this shader to contain some useful matrices

    string sv = "#version 150\n"
    "in vec3 aVertexPosition;\n"
    "uniform mat4 viewMatrix, projMatrix;\n"
    "void main(void) {\n"
        "gl_Position = projMatrix * viewMatrix * vec4(aVertexPosition, 1.0);\n"
    "}";

    string sf = "#version 150\n"
    "out vec4 finalColour;\n"
    "void main(void) {\n"
        "finalColour= vec4(0.0, 1.0, 1.0, 1.0);\n"
    "}";

    const char * vv = sv.c_str();
    const char * ff = sf.c_str();

    // Set the sources
    glShaderSource(mVS, 1, &vv,NULL);
    glShaderSource(mFS, 1, &ff,NULL);

    // Compile vertex shader
    glCompileShader(mVS);

    // Now get the status back
    glGetShaderiv(mVS, GL_COMPILE_STATUS, &isCompiled_VS);
    if(isCompiled_VS == false) {
        glGetShaderiv(mVS, GL_INFO_LOG_LENGTH, &maxLength);
 
        vertexInfoLog = new char[maxLength];
        glGetShaderInfoLog(mVS, maxLength, &maxLength, vertexInfoLog);
 
        cerr << "Vertex Shader Error - " << vertexInfoLog << endl;
 
        delete [] vertexInfoLog;
        return;
    }
    
    // Compile the fragment shader
    glCompileShader(mFS);
    glGetShaderiv(mFS, GL_COMPILE_STATUS, &isCompiled_FS);
    if(isCompiled_FS == false) {
        glGetShaderiv(mFS, GL_INFO_LOG_LENGTH, &maxLength);
        fragmentInfoLog = new char[maxLength];
        glGetShaderInfoLog(mFS, maxLength, &maxLength, fragmentInfoLog);
        cerr << "Fragment Shader Error - " << fragmentInfoLog << endl;
        
        delete [] fragmentInfoLog;
        return;
    }

    // Create the program
    
    mProgram = glCreateProgram();

    // Attach the shaders and link
    glAttachShader(mProgram,mVS);
    glAttachShader(mProgram,mFS);
    glLinkProgram(mProgram);

    // check link status

    glGetProgramiv(mProgram, GL_LINK_STATUS, (int *)&IsLinked);
    if(IsLinked == false) {
        glGetProgramiv(mProgram, GL_INFO_LOG_LENGTH, &maxLength);
        shaderProgramInfoLog = new char[maxLength];
        glGetProgramInfoLog(mProgram, maxLength, &maxLength, shaderProgramInfoLog);
        cerr << "Seburo - Shader Program Error " << shaderProgramInfoLog << endl;
        delete []  shaderProgramInfoLog;
        return;
    }


    vertexLoc = glGetAttribLocation(mProgram,"aVertexPosition");

    // Grab our locations
    projMatrixLoc = glGetUniformLocation(mProgram, "projMatrix");
    viewMatrixLoc = glGetUniformLocation(mProgram, "viewMatrix");
}

/*
 * Create a buffer for our first ever triangle
 */

void BasicApp::createBuffers() {

    vector<float> verts;

    vector<float> colours;
    
    verts += 0.0f, 0.0f, 0.0f,
        1.0, 0.0f, 0.0f, 
        0.5, 1.0, 0.0f;
        
    colours += 1.0f,0.0f,0.0f,1.0f,
        0.0f,0.0f,1.0f,1.0f,
        0.0f,1.0f,0.0f,1.0f;

    glGenVertexArrays(1, vao);

    glBindVertexArray(vao[0]);
  
    glGenBuffers(2,handle);
    glBindBuffer(GL_ARRAY_BUFFER, handle[0]);
    glBufferData(GL_ARRAY_BUFFER, verts.size() * sizeof(float), &verts[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(vertexLoc);
    glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, 0, 0, 0);

    CXGLERROR

    glBindBuffer(GL_ARRAY_BUFFER, handle[1]);
    glBufferData(GL_ARRAY_BUFFER, colours.size() * sizeof(float), &colours[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(colorLoc);
    glVertexAttribPointer(colorLoc, 4, GL_FLOAT, 0, 0, 0);

    CXGLERROR // Handy macro for checking OpenGL Errors
}


/*
 * Called as fast as possible. Not set FPS wise but dt is passed in
 */
		
void BasicApp::display(double_t dt){

    glClearBufferfv(GL_COLOR, 0, &glm::vec4(0.9f, 0.9f, 0.9f, 1.0f)[0]);
    GLfloat depth = 1.0f;
    glClearBufferfv(GL_DEPTH, 0, &depth );

    glUseProgram(mProgram);

    glUniformMatrix4fv(projMatrixLoc, 1, GL_FALSE, glm::value_ptr(projMatrix));
    glUniformMatrix4fv(viewMatrixLoc, 1, GL_FALSE, glm::value_ptr(viewMatrix));

    glBindVertexArray(vao[0]);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glUseProgram(0);


}

/*
 * This is called by the wrapper function when an event is fired
 */

void BasicApp::processEvent(MouseEvent e){

}

/*
 * Called when the window is resized. You should set cameras here
 */

void BasicApp::processEvent(ResizeEvent e){
    cout << "Window Resized:" << e.mW << "," << e.mH << endl;

    glViewport(0,0,e.mW,e.mH);
}

void BasicApp::processEvent(KeyboardEvent e){
    cout << "Key Pressed: " << e.mKey << endl;
}

/*
 * Main function - uses boost to parse program arguments if not OSX
 */

int main (int argc, const char * argv[]) {
  
// We dont bother parsing in the case of OSX due to bundling
#ifndef _OPENGLCOURSE_OSX
    // Declare the supported options.
    po::options_description desc("Allowed options");
    desc.add_options()
    ("help", "OpenGLCourse Basic Application - No Options")
    ;
    
    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);
    

    if (vm.count("help")) {
        cout << desc << "\n";
        return 1;
    }
#endif
  
    BasicApp b;

    // Launch our isntance of GLFW, sending the major and minor numbers

    GLFWApp a(b, 800, 600, false, argc, argv, "05_Matrices", 4, 1);

    return EXIT_SUCCESS;

}