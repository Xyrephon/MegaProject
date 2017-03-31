//
//  Meme.cpp
//  MegaProject
//
//  Created by Tucker, Jonah on 3/17/17.
//  Copyright © 2017 Tucker, Jonah. All rights reserved.
//

#include "Meme.hpp"

Meme :: Meme()
{
    this->title = "boring";
    this->dankness = 0;
    this->hipsterQuotient = -.9999;
    this->mainstream = true;
}

Meme :: Meme(string title)
{
    this->title = title;
    this->dankness = title.length();
    this->hipsterQuotient = 3.14;
    this->mainstream = true;
}

int Meme :: getDankness()
{
    return dankness;
}

double Meme :: getHipsterQuotient()
{
    return hipsterQuotient;
}

string Meme :: getTitle()
{
    return title;
}

bool Meme :: isMainstream()
{
    return mainstream;
}

void Meme :: setTitle(string title)
{
    this ->title = title;
}

void Meme :: setDankness(int dank)
{
    this->dankness = dank;
}

void Meme :: setHipsterQuotient(double quotient)
{
    this->hipsterQuotient = quotient;
}

void Meme :: setMainstream(bool isMain)
{
    this->mainstream = isMain;
}

bool Meme :: operator < (Meme & comparedMeme)
{
    if(this->isMainstream() && comparedMeme.isMainstream())
    {
        if(this->getDankness() < comparedMeme.getDankness())
        {
            return true;
        }
        return false;
    }
    
    return false;
}
