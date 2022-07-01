

#include <iostream>
#include<time.h>
// bir sınıf bir sınıfa sahip midir veya bir sınıf bir sinifi genişletir mi
//is a
//has a //deste sınıfı kart sınıfına sahip midir

using namespace std;
#define kupa (0)
#define sinek (1)
#define maca (2)
#define karo (3)


#define as (0)
#define vale (10)
#define kiz (11)
#define kral (12)
class PlayingCards
{
private :
    int seri;
    int deger;
public :
    PlayingCards(int seri = kupa , int deger=2 ): seri(seri ), deger(deger){}
    int getSeri()const { return seri; }
    int getDeger()const { return deger; }
    int yazdir()const
    {
        switch (seri) {
        case kupa:
            cout << "kupa";
            break;
        case sinek:
            cout << "sinek";
            break;
        case maca:
            cout << "maca";
            break;
        case karo:
            cout << "karo";
            break;
        }
        switch (deger) {
        case as:
            cout << "As";
            break;
        case vale:
            cout << "vale";
            break;
        case kiz:
            cout << "kız";
            break;
        case kral:
            cout << "kral";
            break;
        default:
            cout << deger + 1 ; //programlamada indis 0 dan başlattık 1 + diyerek hatayı engeller

        }
        cout << endl;
    }
  

};

class Deste
{
    PlayingCards cards[52];
    int top; //kart dağıtma

public:
    Deste()
    {
        PlayingCards cards[52];
        for (int i = 0; i < 52; i++) {
            cards[i] = PlayingCards(i / 13, i % 13); //mod alma i değeri mod
            
    }

    }
    void yazdir() {
        for (int i = 0; i < 52; i++) 
        {
            cards[i].yazdir();
        }
    }
    //desteyi karıştırma işlemi 
    void karistir(int kackare = 50) {
        PlayingCards temp;
        for (int i = 0; i < kackare; i++) {
            int x = rand() % 52;
            int y = rand() % 52;
            temp = cards[x];
            cards[x] = cards[y];
            cards[y] = temp;
            //deste karıştırıken 50 kere karıştı
            //ne kadar karıştırırsak o kadar yer değiştirir
        }
    }
    PlayingCards getir() {
        return cards[top++];//dağıttığım kartı bir daha dağıtmamak için top++ diyoruz 
    }

};
    
int main()
{
    srand(time(0));
    Deste d;
    d.yazdir();
    d.karistir(100);
    cout << endl << endl;
    d.yazdir();
    cout << endl << endl;
    d.getir().yazdir();
    d.getir().yazdir();
  //  PlayingCards p(karo, 8);
  //  cout << p.getDeger() << endl;
    //cout << p.getSeri() << endl;

  //  p.yazdir();
    return 0;
}

