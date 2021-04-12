#include "jeu.hpp"
#include "tableau.hpp"
using namespace std;

unsigned int max(unsigned int a, unsigned int b)
{
    return (a > b) ? a : b;
}
vector<Monstre> programmationDynamique(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
    vector<Monstre> final;
    unsigned int y, x;
    unsigned int n = monstres.size();
    unsigned int dimensions[3] = {n+1, magie_rouge+1, magie_bleue+1};
    Tableau<unsigned int> tab (std::vector<unsigned int>(dimensions, dimensions + 3));
    for (int i = 0; i <= n; i++){
        for (int r = 0; r <= magie_rouge; r++){
            for (int b = 0; b <= magie_bleue; b++){
                if(i==0 || r==0 || b==0 ){
                    tab.at(i,r,b)=0; }
                else {
                   y = tab.at(i-1,r,b);
                   if(monstres.at(i-1).magieRouge()>r || monstres.at(i-1).magieBleue()>b) {
                       tab.at(i,r,b) = y;
                   }
                   else {
                       x = tab.at(i-1, r-monstres.at(i-1).magieRouge(), b-monstres.at(i-1).magieBleue()) + monstres.at(i-1).degat();
                       tab.at(i,r,b) = max(x, y);
                   }
                }
            }
        }
    }
    x  = tab.at(n, magie_rouge, magie_bleue);
    unsigned int red = magie_rouge;
    unsigned int blue = magie_bleue;
    for (int i = n; i > 0 && x > 0; i--){
        if (x == tab.at(i-1, red, blue))
            continue;
        else {
            final.push_back(monstres.at(i-1));
            x = x - monstres.at(i-1).degat();
            red = red - monstres.at(i-1).magieRouge();
            blue = blue - monstres.at(i-1). magieBleue();
        }
    }
    return final;
}







































