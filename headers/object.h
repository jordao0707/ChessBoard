// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////
#ifndef _OBJECT_
#define _OBJECT_
#include <vector>
#include<glm/glm.hpp>


class Cubo{
    private:
        glm::vec3 vertices[8]; //vetor para guardar 8 pontos (qtd de vértices de um cubo)
        int       faces[6][4]; //vetor para guardar os índices dos vértices que compõe cada face
        glm::vec3 cor;         //cor do cubo
    public:
        Cubo();
        void setCor(float r, float g, float b);
        void desenha();
};


#endif // CUBO_H