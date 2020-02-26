#include <iostream>
#include <cstring>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <random>
#include <vector>
#include <ctime>
#include <random>
#include "agent.h"

#define Pi 3.1415

int main(){
    int i = 0, j = 0, k = 0;
    bool flag = true;
    int num = 5;//agent* mission = nullptr;
    double x1,y1,x2,y2;
    vector<agent*> AgentVector;
    for(i = 0; i < num; i++){
        AgentVector.push_back(new agent);
        AgentVector.at(i)->random_ori();
        AgentVector.at(i)->random_tag();
        AgentVector.at(i)->Flag();
    }
    while(flag){
        for(i = 0;i < num;i++){
            flag = flag&&(AgentVector.at(i)->Flag());
        }
        for(i = 0;i < num;i++){
            if(k == 0){
                AgentVector.at(i)->store_location(i,num);
            }
            for(j = 0;j < num;j++){
                if(i != j){
                    x1 = AgentVector.at(j)->get_x_cur();
                    y1 = AgentVector.at(j)->get_y_cur();
                    x2 = AgentVector.at(j)->get_x_tag();
                    y2 = AgentVector.at(j)->get_y_tag();
                    AgentVector.at(i)->set_Location(x1,y1,x2,y2,j);
                }
                else{
                    continue;
                }
            }
        }
        for(i = 0;i < num; i++){
           AgentVector.at(i)->weight(num);
           AgentVector.at(i)->LSMT(num);
           AgentVector.at(i)->neighbor_pair_index(num);
           AgentVector.at(i)->Distance(num);
           AgentVector.at(i)->agent_navigation(num);
           AgentVector.at(i)->navigation_check(num,i);
        }
        k = k + 1;
    }
    cout<<"mission complete!"<<endl;
    return 0;
}

