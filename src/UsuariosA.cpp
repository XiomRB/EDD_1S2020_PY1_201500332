#include "UsuariosA.h"

UsuariosA::UsuariosA()
{
    this->raiz = 0;
    this->dibujo = "";
}
NodoB *UsuariosA::getRaiz(){
    return this->raiz;
}

NodoB *UsuariosA::insertarAB(NodoB *raiz,string us){
    if(raiz==0){
        raiz = new NodoB(us);
        return raiz;
    }else if(us.compare(raiz->getUsuario())<0){
        NodoB *aux = this->insertarAB(raiz->getIzq(),us);
        raiz->setIzq(aux);
    }else if(us.compare(raiz->getUsuario())>0){
        NodoB *aux = this->insertarAB(raiz->getDer(),us);
        raiz->setDer(aux);
    }
    return raiz;
}

void UsuariosA::insertar(string us){
    this->raiz = insertarAB(this->raiz,us);
}

void UsuariosA::inorderAB(NodoB *raiz){
    if(raiz!=0){
        this->inorderAB(raiz->getIzq());
        this->dibujo += "\"" + raiz->getUsuario() + "\" -> ";
        this->inorderAB(raiz->getDer());
    }
}
string UsuariosA::inorder(){
    if(this->raiz==0){
        return "";
    }
    this->dibujo = "rankdir = LR;\nnode [shape = box];\n";
    this->inorderAB(this->raiz);
    int t = this->dibujo.size();
    dibujo[t-3] = ';';
    dibujo[t-2] = '\n';
    return this->dibujo;
}

NodoB *UsuariosA::getJugador(string usuario){
    if(this->raiz == 0){
        return 0;
    }else{
        NodoB *aux = this->raiz;
        while(aux->getUsuario().compare(usuario)!=0){
            if(aux->getUsuario().compare(usuario)>0) aux = aux->getIzq();
            else aux = aux->getDer();
            if(aux == 0)return 0;
        }
        return aux;
    }
}

void UsuariosA::preorderAB(NodoB *raiz){
    dibujo += "\"" + raiz->getUsuario() + "\" -> ";
    if(raiz->getIzq()!=0) this->preorderAB(raiz->getIzq());
    if(raiz->getDer()!=0) this->preorderAB(raiz->getDer());

}

string UsuariosA::preorder(){
    if(this->raiz==0) return "";
    this->dibujo = "rankdir = LR;\nnode [shape = box];\n";
    this->preorderAB(this->raiz);
    int t = this->dibujo.size();
    dibujo[t-3] = ';';
    dibujo[t-2] = '\n';
    return this->dibujo;
}
void UsuariosA::postorderAB(NodoB *raiz){
    if(raiz->getIzq()!=0) this->postorderAB(raiz->getIzq());
    if(raiz->getDer()!=0) this->postorderAB(raiz->getDer());
    dibujo += "\"" + raiz->getUsuario() + "\" -> ";

}

string UsuariosA::postorder(){
    if(this->raiz==0) return "";
    this->dibujo = "rankdir = LR;\nnode [shape = box];\n";
    this->postorderAB(this->raiz);
    int t = this->dibujo.size();
    dibujo[t-3] = ';';
    dibujo[t-2] = '\n';
    return this->dibujo;
}
void UsuariosA::dibujarAB(NodoB *raiz){
    if(raiz!=0){
        if(raiz->getIzq()!=0) this->dibujo += "\"" + raiz->getUsuario() + "\" -> \"" + raiz->getIzq()->getUsuario() + "\";\n";
        if(raiz->getDer()!=0) this->dibujo += "\"" + raiz->getUsuario() + "\" -> \"" + raiz->getDer()->getUsuario() + "\";\n";
        this->dibujarAB(raiz->getIzq());
        this->dibujarAB(raiz->getDer());
    }
}

string UsuariosA::dibujar(){
    if(this->raiz !=0){
        if(this->raiz->getDer() == 0 && this->raiz->getIzq()==0) this->dibujo = "\"" + raiz->getUsuario() + "\"";
        else dibujarAB(this->raiz);
    }
     return this->dibujo;
}
UsuariosA::~UsuariosA()
{
    //dtor
}
