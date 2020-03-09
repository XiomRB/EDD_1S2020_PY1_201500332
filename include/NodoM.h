#ifndef NODOM_H
#define NODOM_H


class NodoM
{
    public:
        NodoM(int,int,char,int);
        void setSig(NodoM *);
        void setAnt(NodoM *);
        void setArriba(NodoM *);
        void setAbajo(NodoM *);
        void setX(int);
        void setY(int);
        void setLetra(char);
        NodoM *getAnt();
        NodoM *getSig();
        NodoM *getAbajo();
        NodoM *getArriba();
        int getX();
        int getY();
        char getLetra();
        virtual ~NodoM();
        int nn;

    protected:

    private:
        NodoM *ant;
        NodoM *sig;
        NodoM *arriba;
        NodoM *abajo;
        int x;
        int y;
        char letra;
};

#endif // NODOM_H
