#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <vector>  //inclui a classe vector, que implementa um vetor de tamanho variável 
#include <iostream>

using namespace std;

typedef struct{
    float x;
    float y;
} Ponto;

//Estrutura para guardar os índices dos pontos que indicarão o iní­cio e o final de um segmento de reta
typedef struct{
    int vi;
    int vf;
} Segmento;

//VariÃ¡veis globais
vector<Ponto*> pontos;       //vetor para guardar todos os pontos gerados
vector<Segmento*> segmentos; //vetor para guardar todos os segmentos gerados
double mouse_x = 0;
double mouse_y = 0;
int width = 0;
int height = 0;  
      
void clickAction(GLFWwindow* window, int button, int action, int mods);
void initOpenGL();
void draw();

void initOpenGL(){
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(10.0); 
    glLineWidth(3.0);   
}

void screenResize( int w , int h){
      
    glViewport(0,0, w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); 
   
    float aspect = (float)w / (float)h;
    double x = 10*(w>=h?aspect:1);
    double y = 10/(w<h?aspect:1);
    glOrtho(0,x,y,0,1,-1);
    
}

void draw(){
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS); //Primitiva utilizada para desenhar pontos.
        for(unsigned int i = 0 ; i < pontos.size() ; i++) 
            glVertex2f(pontos[i]->x, pontos[i]->y);
    glEnd();
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES); //Primitiva utilizada para desenhar segmentos de reta desconectados.
        for(unsigned int i = 0 ; i < segmentos.size() ; i++){
            //Pegando os Ã­ndices dos vÃ©rtices inicial e final
            int vi = segmentos[i]->vi;
            int vf = segmentos[i]->vf;
            
            //Usando esses Ã­ndices no vetor pontos para determinar as coordenadas que definirÃ£o o ponto inicial e final do segmento
            glVertex2f(pontos[vi]->x, pontos[vi]->y);
            glVertex2f(pontos[vf]->x, pontos[vf]->y);
        }
    glEnd();
    
    glFlush();  
;  
}

void mouseAction(GLFWwindow* window, int button, int action, int mods){
    float coord_x = mouse_x;
    float coord_y = mouse_y; 
    
    if(button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){ 
        Ponto *novoPonto = new Ponto;
        novoPonto->x = coord_x; 
        novoPonto->y = coord_y;
        pontos.push_back(novoPonto); //insere o novo ponto alocado no final do vetor 'pontos'
    }
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){ 
        //Cria dois pontos com exatamente as mesmas coordenadas
        Ponto *novoPonto1 = new Ponto;
        Ponto *novoPonto2 = new Ponto;
        novoPonto1->x = novoPonto2->x = coord_x; 
        novoPonto1->y = novoPonto2->y = coord_y;
        
        unsigned int indice = pontos.size(); //Pego a quantidade de pontos antes de adicionar os novos, porque servirÃ¡ para saber onde esses dois pontos foram adicionados
        pontos.push_back(novoPonto1);
        pontos.push_back(novoPonto2);
        
        //Cria um segmento de reta. O atributo 'vi' guarda o Ã­ndice do vÃ©rtice inicial do segmento e o atributo 'vf' guarda o Ã­ndice final do segmento.
        Segmento *novoSegmento = new Segmento;
        novoSegmento->vi = indice;
        novoSegmento->vf = indice+1;
        segmentos.push_back(novoSegmento); //insere o novo segmento no final do vetor 'segmentos'
    }    
}

void mousePosition(GLFWwindow* window, double xpos, double ypos){
    float aspect = (float)width / (float)height;
    double x = 10*(width>=height?aspect:1);
    double y = 10/(width<height?aspect:1);
   
    x = xpos/width * x;
    y = ypos/height * y;
    mouse_x = x;
    mouse_y = y;
    
    if(pontos.size() > 0){
        pontos.back()->x = x;
        pontos.back()->y = y;
    }
}
int main(int argc, char** argv){
    glfwInit();
    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    GLFWwindow *window = glfwCreateWindow(mode->width, mode->height, "Lista 1 CG",NULL, NULL);
    glfwMakeContextCurrent(window);
    // glfwSetKeyCallback (window, key_callback);
    
    initOpenGL();
    while (!glfwWindowShouldClose(window)){
          glClear(GL_COLOR_BUFFER_BIT);
      
        glfwSetMouseButtonCallback(window, mouseAction);
        glfwSetCursorPosCallback(window, mousePosition);
        glfwGetFramebufferSize(window,&width,&height);
        screenResize(width,height);
        draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();    
    return 0;
}






