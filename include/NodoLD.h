#ifndef NODOLD_H
#define NODOLD_H


class NodoLD
{
    public:
        NodoLD(char,int);
        int getPunteo();
        char getLetra();
        void setPunteo(int);
        void setLetra(char);
        void setSig(NodoLD *);
        void setAnt(NodoLD *);
        NodoLD *getSig();
        NodoLD *getAnt();
        virtual ~NodoLD();

    protected:

    private:
        int punteo;
        char letra;
        NodoLD *sig;
        NodoLD *ant;
};

#endif // NODOLD_H
