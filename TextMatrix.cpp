//
// Created by pasri on 23/07/2022.
//

#include "TextMatrix.h"

const float PROB_SPAWN {0.75};
const float PROB_DIM {0.45};
const float PROB_CHANGE {0.95};

std::random_device rng;
std::uniform_int_distribution<int> getChar {33, 120};
std::uniform_real_distribution<float> getChance {0.0f,1.0f};

cell& TextMatrix::at(int x, int y) {
    return tMatrix[x][y];
}

void TextMatrix::fade_change() {
    for (int i=0; i<rows; ++i) {
        for (int j = 0; j <cols; ++j) {
            auto& thisCell{tMatrix[i][j]};
            //randomly change characters
            if (getChance(rng) < PROB_CHANGE || thisCell.symbol == 0) {
                thisCell.symbol = static_cast<char>(getChar(rng));
            }
            //randomly dim the cells
            if (getChance(rng) < PROB_DIM) {
                if (thisCell.intensity > 0) thisCell.intensity--;
            }
        }
    }
}

void TextMatrix::update() {
    if(getChance(rng) < PROB_SPAWN){
        add_drips();
    }
    update_drips();
    fade_change();
}

void TextMatrix::add_drips() {
    for(auto & drip : m_drips){
        if (!drip.live) {
            drip.live = true;
            // drips start at the top row: y = 0;
            drip.dPos = {getxPos(rng), 0};
            drip.bright =  getxPos(rng) % 2;
            // doing this we get one new drip at a time
            return;
        }
    }
}

void TextMatrix::update_drips() {
    for(auto & drip : m_drips){
        // get reference to cell at current drip location
        if (drip.live) {
            auto& thisCell = tMatrix[drip.dPos.first][drip.dPos.second];
            if (drip.bright) {
                thisCell.intensity = MAX_INTENSITY;
            } else {
                thisCell.intensity = MIN_INTENSITY;
            }
            // drips die when they hit the bottom of the screen
            if(++drip.dPos.second >= cols-1) drip.live=false;
        }
    }
}


