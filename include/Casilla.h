#ifndef CASILLA_H
#define CASILLA_H


class Casilla
{
    public:
        Casilla(int,int,int);
        Casilla();
        int x;
        int y;
        int punteo;
        virtual ~Casilla();

    protected:

    private:
};

#endif // CASILLA_H
