// Autor: Jordão Rodrigues Dantas
// Mátricula: 403686
// ///// CHESS BOARD //////
#ifndef _MOUSE_
#define _MOUSE_
#include <vector>
#include "./square.h"
void mouseAction(GLFWwindow* window, int button, int action, int mods, std::vector<Square*> *sqrs);
#endif