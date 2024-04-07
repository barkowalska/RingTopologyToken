#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

struct verticle
{
    int next;
    list<int> requests;
    bool token{ false };
    bool want_to_request{ false };

};

void algo(verticle* ring, int nodesNum);


int main()
{
    int nodesNum;
    int first_token;
    int requests_num;

    fstream file;
   
    file.open("./example.txt");
    file >> nodesNum;
    file >> first_token;
    file >> requests_num;
    vector<int> requesting_nodes;
    for (int i = 0; i < requests_num; i++)
    {
        int n;
        file >> n;
        requesting_nodes.push_back(n);
    }

    verticle* ring = new verticle[nodesNum];
    for (int i = 0; i < nodesNum; i++)
    {
        ring[i].next = (i == nodesNum - 1) ? 0 : i + 1;
        if (i == first_token) ring[i].token = true;
        for (int k = 0; k < requests_num; k++)
        {
            if (i == requesting_nodes[k])ring[i].want_to_request = true;
        }


    }
    
    file.close();

    algo(ring, nodesNum);
    delete[]ring;
    return 0;

    
}

void algo(verticle* ring, int nodesNum)
{
    bool running = 1;

    while (running == 1)
    {
        int o;
        bool add_req = false;
        cout << "Add request? [1/0]: " << endl;
        cin >> add_req;

        if (add_req == 1)
        {
            cout << "Which node: " << endl;
            cin >> o;
            ring[o].want_to_request = 1;
        }
        
        for (int i = 0; i < nodesNum; i++)
        {
            int k = ring[i].next;

            if (ring[i].token == 1) 
                cout << "[T] Node " << i << " holds the token\n";

            cout << "Node " << i << " received request from: ";

            for (int m : ring[i].requests)
                cout << m << ", ";
            cout << endl;

            if (ring[i].want_to_request == 1)
            {
                ring[i].requests.push_back(i);
                ring[i].want_to_request = 0;
                cout << "Node " << i << " requests token\n";
            }
            
            if (ring[i].token == 1)
            {
                if (ring[i].requests.front() == i)
                {
                    cout << "[$] Node " << i << " used the token!" << endl;
                    ring[i].requests.pop_front();
                    //ring[i].chce_token = 0;                  

                }
                
                if (!ring[i].requests.empty())
                {
                    ring[i].token = 0;
                    ring[k].token = 1;
                }
            }
            swap(ring[i].requests, ring[k].requests);
            cout << endl;
        }
        
        running = 0;
        for (int k = 0; k < nodesNum; k++)
        {

            if (!ring[k].requests.empty())
                running = 1;
        }


    }
}




