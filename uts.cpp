#include "include/glad/glad.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Muhammad Izzatul Haq
// 1904618

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main(){
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }  

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//Resets all window hints to their default values.
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "UTS Task", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: could not open window\n");
        glfwTerminate();//destroy all windows
        return 1;
    }
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        fprintf(stderr, "ERROR: failed initialized GLAD\n");
        return -1;
    }




    //== Background Vertex
    float verticesBg[] = {
        -1.0f, -1.0f, 0.0f,  1.0f, 0.0f, 1.0f,  0.0f, 1.0f,
         1.0f, -1.0f, 0.0f,  0.0f, 1.0f, 1.0f,  1.0f, 1.0f,
         1.0f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f,  1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 0.0f,
    };

    unsigned int indicesBg[] = {  
        0, 1, 2,
        0, 2, 3
    };

    unsigned int vboBg, vaoBg, eboBg;
    glGenVertexArrays(1, &vaoBg);
    glGenBuffers(1, &vboBg);
    glGenBuffers(1, &eboBg);

    
    glBindVertexArray(vaoBg);

    glBindBuffer(GL_ARRAY_BUFFER, vboBg);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesBg), verticesBg, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboBg);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesBg), indicesBg, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);//
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture coordinate attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    //== Geo Vertex
    float verticesGeo[] = {
        0.7f, 1.0f, 0.0f, (241 / 255.0), (95 / 255.0), (49 / 255.0),
        1.0f, 1.0f, 0.0f, (241 / 255.0), (95 / 255.0), (49 / 255.0),
        0.61f, 0.42f, 0.0f, (235 / 255.0), (27 / 255.0), (70 / 255.0),
        1.0f, 1.0f, 0.0f, (248 / 255.0), (139 / 255.0), (40 / 255.0),
        0.61f, 0.42f, 0.0f, (245 / 255.0), (119 / 255.0), (43 / 255.0),
        1.0f, 0.33f, 0.0f, (242 / 255.0), (95 / 255.0), (51 / 255.0),
        0.61f, 0.42f, 0.0f, (71 / 255.0), (173 / 255.0), (66 / 255.0),
        1.0f, 0.33f, 0.0f, (75 / 255.0), (175 / 255.0), (66 / 255.0),
        0.72f, 0.03f, 0.0f, (71 / 255.0), (173 / 255.0), (68 / 255.0),
        1.0f, 0.33f, 0.0f, (0 / 255.0), (147 / 255.0), (68 / 255.0),
        0.72f, 0.03f, 0.0f, (0 / 255.0), (147 / 255.0), (68 / 255.0),
        1.0f, -0.1f, 0.0f, (0 / 255.0), (147 / 255.0), (68 / 255.0),
        0.72f, 0.03f, 0.0f, (1 / 255.0), (115 / 255.0), (255 / 255.0),
        1.0f, -0.1f, 0.0f, (1 / 255.0), (115 / 255.0), (255 / 255.0),
        0.8f, -0.65f, 0.0f, (1 / 255.0), (115 / 255.0), (255 / 255.0),
        0.38f, -0.19f, 0.0f, (0 / 255.0), (196 / 255.0), (255 / 255.0),
        0.72f, 0.03f, 0.0f, (0 / 255.0), (196 / 255.0), (255 / 255.0),
        0.8f, -0.65f, 0.0f, (0 / 255.0), (163 / 255.0), (255 / 255.0),
        1.0f, -0.69f, 0.0f, (250 / 255.0), (178 / 255.0), (48 / 255.0),
        1.0f, -0.1f, 0.0f, (250 / 255.0), (178 / 255.0), (48 / 255.0),
        0.8f, -0.65f, 0.0f, (250 / 255.0), (178 / 255.0), (48 / 255.0),
        1.0f, -0.69f, 0.0f, (244 / 255.0), (126 / 255.0), (52 / 255.0),
        1.0f, -1.0f, 0.0f, (244 / 255.0), (126 / 255.0), (52 / 255.0),
        0.8f, -0.65f, 0.0f, (244 / 255.0), (126 / 255.0), (52 / 255.0),
        0.73f, -1.0f, 0.0f, (30 / 255.0), (158 / 255.0), (69 / 255.0),
        1.0f, -1.0f, 0.0f, (30 / 255.0), (158 / 255.0), (69 / 255.0),
        0.8f, -0.65f, 0.0f, (30 / 255.0), (158 / 255.0), (69 / 255.0),
        0.73f, -1.0f, 0.0f, (113 / 255.0), (188 / 255.0), (65 / 255.0),
        0.44f, -0.61f, 0.0f, (97 / 255.0), (182 / 255.0), (64 / 255.0),
        0.8f, -0.65f, 0.0f, (113 / 255.0), (188 / 255.0), (65 / 255.0),
        0.38f, -0.19f, 0.0f, (252 / 255.0), (80 / 255.0), (156 / 255.0),
        0.44f, -0.61f, 0.0f, (246 / 255.0), (20 / 255.0), (155 / 255.0),
        0.8f, -0.65f, 0.0f, (246 / 255.0), (20 / 255.0), (155 / 255.0),
        0.38f, -0.19f, 0.0f, (252 / 255.0), (80 / 255.0), (156 / 255.0),
        0.44f, -0.61f, 0.0f, (253 / 255.0), (106 / 255.0), (156 / 255.0),
        0.27f, -0.7f, 0.0f, (253 / 255.0), (106 / 255.0), (156 / 255.0),
        0.44f, -0.61f, 0.0f, (248 / 255.0), (151 / 255.0), (52 / 255.0),
        0.73f, -1.0f, 0.0f, (244 / 255.0), (116 / 255.0), (52 / 255.0),
        0.32f, -1.0f, 0.0f, (250 / 255.0), (175 / 255.0), (50 / 255.0),
        0.27f, -0.7f, 0.0f, (255 / 255.0), (200 / 255.0), (48 / 255.0),
        0.32f, -1.0f, 0.0f, (253 / 255.0), (197 / 255.0), (48 / 255.0),
        0.44f, -0.61f, 0.0f, (250 / 255.0), (175 / 255.0), (50 / 255.0),
        0.1f, -0.8f, 0.0f, (245 / 255.0), (133 / 255.0), (52 / 255.0),
        0.32f, -1.0f, 0.0f, (248 / 255.0), (155 / 255.0), (51 / 255.0),
        0.27f, -0.7f, 0.0f, (253 / 255.0), (189 / 255.0), (49 / 255.0),
        0.1f, -0.8f, 0.0f, (242 / 255.0), (97 / 255.0), (50 / 255.0),
        0.32f, -1.0f, 0.0f, (241 / 255.0), (90 / 255.0), (52 / 255.0),
        0.05f, -1.0f, 0.0f, (240 / 255.0), (62 / 255.0), (61 / 255.0),
    };

    unsigned int indicesGeo[] = {  
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
        12, 13, 14,
        15, 16, 17,
        18, 19, 20,
        21, 22, 23,
        24, 25, 26,
        27, 28, 29,
        30, 31, 32,
        33, 34, 35,
        36, 37, 38,
        39, 40, 41,
        42, 43, 44,
        45, 46, 47
    };


    unsigned int vboGeo, vaoGeo, eboGeo;
    glGenVertexArrays(1, &vaoGeo);
    glGenBuffers(1, &vboGeo);
    glGenBuffers(1, &eboGeo);

    
    glBindVertexArray(vaoGeo);

    glBindBuffer(GL_ARRAY_BUFFER, vboGeo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesGeo), verticesGeo, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboGeo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesGeo), indicesGeo, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    


    

    // ===== Shader =====
    
    const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(aPos, 1.0);\n"
    "    ourColor = aColor;\n"
    "    TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
    "}\0";

    // == Texture Fragment
    const char *fragmentShaderSource1 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;"
    "in vec2 TexCoord;\n"
    "uniform sampler2D texture1;\n"
    "void main()\n"
    "{\n"
    "    FragColor = texture(texture1, TexCoord);\n"
    "}\n\0";

    //vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    //fragment shader
    unsigned int fragmentShaderTexture = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderTexture, 1, &fragmentShaderSource1, NULL);
    glCompileShader(fragmentShaderTexture);

    //link shaders
    unsigned int shaderProgramTexture = glCreateProgram();
    glAttachShader(shaderProgramTexture, vertexShader);
    glAttachShader(shaderProgramTexture, fragmentShaderTexture);
    glLinkProgram(shaderProgramTexture);

    // == Color Fragment
    const char *fragmentShaderSource2 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "in vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "    FragColor = vec4(ourColor, 0.8);\n"
    "}\n\0";

    //fragment shader
    unsigned int fragmentShaderColor = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderColor, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShaderColor);

    //link shaders
    unsigned int shaderProgramColor = glCreateProgram();
    glAttachShader(shaderProgramColor, vertexShader);
    glAttachShader(shaderProgramColor, fragmentShaderColor);
    glLinkProgram(shaderProgramColor);

    //activate blend
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);




    //===== Texture =====
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);


    //set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);



    // Load and generate the texture
    int width, height, nrChannels;
    unsigned char *data = stbi_load("nature.jpg", &width, &height, &nrChannels, 0);

    if (data){
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);//Specify a two-dimensional texture image
        glGenerateMipmap(GL_TEXTURE_2D);//generate mipmaps for a specified texture target
    }
    else{
        fprintf(stderr, "Failed to load texture");
    }

    stbi_image_free(data);






    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // render
        glClearColor(0.3f, 0.3f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Bind texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // draw background
        glUseProgram(shaderProgramTexture);
        glBindVertexArray(vaoBg); 
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // draw Geo
        glUseProgram(shaderProgramColor);
        glBindVertexArray(vaoGeo); 
        glDrawElements(GL_TRIANGLES, 49, GL_UNSIGNED_INT, 0);
        
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &vaoBg);
    glDeleteBuffers(1, &vaoBg);

    glDeleteVertexArrays(1, &vaoGeo);
    glDeleteBuffers(1, &vaoGeo);

    glDeleteProgram(shaderProgramTexture);
    glDeleteProgram(shaderProgramColor);

    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}
