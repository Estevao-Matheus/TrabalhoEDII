#ifndef TRABALHOEDII_OBJETO_H
#define TRABALHOEDII_OBJETO_H


class Objeto {
public:
    Objeto();
    Objeto(int userID, int movieID, float rating);
    ~Objeto();
    void Imprimi();
    int getUserID() const;

    void setUserID(int UserID);

    int getMovieID() const;

    void setMovieID(int MovieID);

    float getRating() const;

    void setRating(float Rating);


private:
    int UserID;
    int MovieID;
    float Rating;
};


#endif //TRABALHOEDII_DADO_H
