#include <jni.h>

#include <GLES2/gl2.h>

#include <stdio.h>
#include <stdlib.h>
static void printGLString(const char *name, GLenum s) {
    const char *v = (const char *) glGetString(s);
}

auto gVertexShader =
        "attribute vec4 vPosition;\n"
                "void main() {\n"
                "  gl_Position = vPosition;\n"
                "}\n";

auto gFragmentShader =
        "precision mediump float;\n"
                "void main() {\n"
                "  gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);\n"
                "}\n";

GLuint loadShader(GLenum shaderType, const char* pSource) {
    GLuint shader = glCreateShader(shaderType);
    if (shader) {
        glShaderSource(shader, 1, &pSource, NULL);
        glCompileShader(shader);
        GLint compiled = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
        if (!compiled) {
            GLint infoLen = 0;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen) {
                char* buf = (char*) malloc(infoLen);
                if (buf) {
                    glGetShaderInfoLog(shader, infoLen, NULL, buf);
                    free(buf);
                }
                glDeleteShader(shader);
                shader = 0;
            }
        }
    }
    return shader;
}

GLuint createProgram(const char* pVertexSource, const char* pFragmentSource) {
    GLuint vertexShader = loadShader(GL_VERTEX_SHADER, pVertexSource);
    if (!vertexShader) {
        return 0;
    }

    GLuint pixelShader = loadShader(GL_FRAGMENT_SHADER, pFragmentSource);
    if (!pixelShader) {
        return 0;
    }

    GLuint program = glCreateProgram();
    if (program) {
        glAttachShader(program, vertexShader);
        glAttachShader(program, pixelShader);
        glLinkProgram(program);
        GLint linkStatus = GL_FALSE;
        glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
        if (linkStatus != GL_TRUE) {
            GLint bufLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &bufLength);
            if (bufLength) {
                char* buf = (char*) malloc(bufLength);
                if (buf) {
                    glGetProgramInfoLog(program, bufLength, NULL, buf);
                }
            }
            glDeleteProgram(program);
            program = 0;
        }
    }
    return program;
}

GLuint gProgram;
GLuint gvPositionHandle;

bool setupGraphics(int w, int h) {
    printGLString("Version", GL_VERSION);
    printGLString("Vendor", GL_VENDOR);
    printGLString("Renderer", GL_RENDERER);
    printGLString("Extensions", GL_EXTENSIONS);

    gProgram = createProgram(gVertexShader, gFragmentShader);
    if (!gProgram) {
        return false;
    }
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");

    glViewport(0, 0, w, h);
    return true;
}

const GLfloat gTriangleVertices[] = { 0.0f, 0.5f, -0.5f, -0.5f,
                                      0.5f, -0.5f };

#include <iomanip> // setprecision
#include <sstream> // stringstream

void renderFrame() {
    std::stringstream stream;
    stream  << "precision mediump float;\n"
            << "void main() {\n"
            << "  gl_FragColor = vec4("
            << std::fixed << static_cast <float> (rand()) / static_cast <float> (RAND_MAX) << ","
            << std::fixed << std::setprecision(2) << static_cast <float> (rand()) / static_cast <float> (RAND_MAX) << ","
            << std::fixed << std::setprecision(2) << static_cast <float> (rand()) / static_cast <float> (RAND_MAX) << ","
            <<"1.0);\n"
            << "}\n";
    auto glColor = stream.str().c_str();

    gProgram = createProgram(gVertexShader, glColor);
    gvPositionHandle = glGetAttribLocation(gProgram, "vPosition");
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(gProgram);

    glVertexAttribPointer(gvPositionHandle, 2, GL_FLOAT, GL_FALSE, 0, gTriangleVertices);
    glEnableVertexAttribArray(gvPositionHandle);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(gProgram);
}

jint timer = 0;

extern "C" {
JNIEXPORT void JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height);
JNIEXPORT void JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_step(JNIEnv * env, jobject obj);
JNIEXPORT void JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_clearTimer();
JNIEXPORT jint JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_getTimer();
};

JNIEXPORT void JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
    setupGraphics(width, height);
}

JNIEXPORT void JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_step(JNIEnv * env, jobject obj)
{
    renderFrame();
    ++timer;
}

JNIEXPORT void JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_clearTimer(){
    timer = 0;
}

JNIEXPORT jint JNICALL Java_com_example_admin_testandroidapp_GL2JNILib_getTimer(){
    return timer;
}
