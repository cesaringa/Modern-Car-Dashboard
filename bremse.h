#ifndef BREMSE_H
#define BREMSE_H


class Bremse
{
    bool bremse = false;

public:
    Bremse();
    bool getBremse();
    void setBremse(bool);
};

#endif // BREMSE_H
