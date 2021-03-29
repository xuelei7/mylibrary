#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


enum Type{
	Move,
	On,
	Off,
};


struct Data{
	Data(Type arg_type,int arg_room_id){
		type = arg_type;
		room_id = arg_room_id;
	}
	Type type;
	int room_id;
};

struct Info{
	void set(int arg_current_room,int arg_num_step,int arg_state){
		current_room = arg_current_room;
		num_step = arg_num_step;
		state  = arg_state;
	}
	int current_room,num_step,state;
	vector<Data> history;
};


int N,M,start = 0,goal;
int POW[16];
int min_cost[32768][15];
vector<int> G[15],button[15];


void func(){

	for(int i = 0; i < N; i++){
		G[i].clear();
		button[i].clear();
	}

	goal = N-1;

	int from,to;

	for(int loop = 0; loop < M; loop++){
		scanf("%d %d",&from,&to);
		from--;
		to--;
		G[from].push_back(to);
		G[to].push_back(from);
	}

	int first_state = 0,tmp;
	for(int i = 0; i < N; i++){
		scanf("%d",&tmp);
		if(tmp == 1){
			first_state += POW[i];
		}
	}

	int num;
	for(int i = 0; i < N; i++){
		scanf("%d",&num);
		for(int k = 0; k < num; k++){
			scanf("%d",&tmp);
			tmp--;
			button[i].push_back(tmp);
		}
	}

	for(int i = 0; i < N; i++){
		sort(button[i].begin(),button[i].end());
	}

	queue<Info> Q;
	Info first;
	first.set(start,0,first_state);
	Q.push(first);

	bool finished = false;
	int target_room,next_room,next_state;

	for(int state = 0; state < POW[N]; state++){
		for(int room = 0; room < N; room++){
			min_cost[state][room] = BIG_NUM;
		}
	}

	min_cost[first_state][start] = 0;

	Type next_type;

	while(!Q.empty()){

		if(Q.front().current_room == goal){
			finished = true;
			if(Q.front().state == POW[goal]){

				printf("You can go home in %d steps.\n",Q.front().num_step);
				for(int i = 0; i < Q.front().num_step; i++){
					switch(Q.front().history[i].type){
					case Move:
						printf("Move to room ");
						break;
					case On:
						printf("Switch on room ");
						break;
					case Off:
						printf("Switch off room ");
						break;
					}
					printf("%d.\n",Q.front().history[i].room_id+1);
				}

				return;
			}
		}

		if(Q.front().num_step > min_cost[Q.front().state][Q.front().current_room]){
			Q.pop();
		}else{

			for(int i = 0; i < button[Q.front().current_room].size(); i++){
				target_room = button[Q.front().current_room][i];

				if(target_room == Q.front().current_room)continue;

				if(Q.front().state & (1 << target_room)){
					next_state = Q.front().state-POW[target_room];
					next_type = Off;
				}else{
					next_state = Q.front().state+POW[target_room];
					next_type = On;
				}

				if(min_cost[next_state][Q.front().current_room] > Q.front().num_step+1){
					min_cost[next_state][Q.front().current_room] = Q.front().num_step+1;
					Info next_info;
					next_info.set(Q.front().current_room,Q.front().num_step+1,next_state);
					for(int k = 0; k < Q.front().num_step; k++){
						next_info.history.push_back(Q.front().history[k]);
					}
					next_info.history.push_back(Data(next_type,target_room));
					Q.push(next_info);
				}
			}

			//移動する場合
			for(int i = 0; i < G[Q.front().current_room].size(); i++){
				next_room = G[Q.front().current_room][i];

				if(Q.front().state & (1 << next_room)){
					if(min_cost[Q.front().state][next_room] > Q.front().num_step+1){
						min_cost[Q.front().state][next_room] = Q.front().num_step+1;
						Info next_info;
						next_info.set(next_room,Q.front().num_step+1,Q.front().state);
						for(int k = 0; k < Q.front().num_step; k++){
							next_info.history.push_back(Q.front().history[k]);
						}
						next_info.history.push_back(Data(Move,next_room));
						Q.push(next_info);
					}
				}
			}
			Q.pop();
		}
	}

	if(finished){
		printf("You can not switch off all lights.\n");
	}else{
		printf("Help me!\n");
	}
}


int main(){

	for(int i = 0; i < 16; i++)POW[i] = pow(2,i);

	while(true){
		scanf("%d %d",&N,&M);
		if(N == 0 && M == 0)break;

		func();
	}

	return 0;
}
