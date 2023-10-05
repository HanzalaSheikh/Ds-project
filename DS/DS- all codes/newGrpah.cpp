#include<iostream>
#include<vector>
#include<list>
#include<iterator>

using namespace std;

class Edge{
    public: 
        int destinationVertexId;
        int weight;

        Edge(){
            destinationVertexId=0;
            weight=0;
        }

        Edge(int desVid, int w){
            destinationVertexId=desVid;
            weight=w;
        }

        void setEdgeValue(int desVid, int w){
            destinationVertexId=desVid;
            weight=w;
        }

        void setDestinationVertexId(int desVid){
            destinationVertexId=desVid;
        }

        void setWeight(int w){
            weight=w;
        }

        int getDestinationVertexId(){
            return destinationVertexId;
        }

        int getWeight(){
            return weight;
        }
};

class Vertex{
    public:
        int stateId;
        string stateName;
        int inDegree=0;
        int outDegree=0;
        list <Edge> edgeList;
        // vector <string> topologicaArray;

        Vertex(){
            stateId=0;
            stateName="";
        }

          Vertex(int SI,int SN){
            stateId=SI;
            stateName=SN;
        }

        void setStateName(string SN){
            stateName=SN;
        }

        void setStateId(int SI){
            stateId=SI;
        }

        int getStateId(){
            return stateId;
        }

        string getStateName(){
            return stateName;
        }

        list <Edge> getEdgeList(){
            return edgeList;
        }

        void printEdgeList() {
        cout << "[";
        for (auto it = edgeList.begin(); it != edgeList.end(); it++) {
        cout << it ->getDestinationVertexId() << "(" << it -> getWeight() << ") --> ";
        }
        cout << "]";
        cout << endl;
  }


};

class Graph{
    public:
        vector <Vertex> vertices;
        vector <string> topologicaArray;


        // checking if vertex exists in the graph or not
        bool checkVertexById(int id){
            for(int i=0;i<vertices.size();i++){
                if(vertices.at(i).getStateId() == id){
                    return true;
                }
            }
            return false;
        }


    	// checking if there is already edge between two vertices 
        bool checkEdgeExistById(int fromVertex,int toVertex){
            Vertex v = getVertexByID(fromVertex);
            list<Edge> e;
            e=v.getEdgeList();
            for(auto it = e.begin(); it != e.end(); it++){
               if( it->getDestinationVertexId() == toVertex){
                return true;
                }
            }
            return false;
        }

        // getting a vertex by id 
        Vertex getVertexByID(int vid) {
            Vertex temp;
            for (int i = 0; i < vertices.size(); i++){
            temp = vertices.at(i);
            if (temp.getStateId() == vid) {
                return temp;
                }
            }
            return temp;
        }


        // adding a vertex in the graph through vector stl 
        void addVertex(Vertex v){
            bool check = checkVertexById(v.getStateId());
            if(check==true){
                cout<<"state already exist with id "<<v.getStateId()<<endl;
            }
            else{
                vertices.push_back(v);
                cout<<"new vertex added sucessfully "<<endl;
            }
        }

        // adding an edge between two vertices
        void addEdgeById(int fromVertex, int toVertex,int weight){
            bool check1= checkVertexById(fromVertex);
            bool check2= checkVertexById(toVertex);

            if((check1 && check2)==true){
                bool check3 = checkEdgeExistById(fromVertex,toVertex);

                if(check3== true){
                    cout<<"edge already exist between "<<getVertexByID(fromVertex).getStateName()<<" and "
                    << getVertexByID(toVertex).getStateName()<<endl;
                }
                else{
                    for(int i=0; i<vertices.size();i++){
                        if(vertices.at(i).getStateId()== fromVertex){
                            Edge e(toVertex,weight);
                            vertices.at(i).edgeList.push_back(e);
                            vertices.at(i).outDegree+=1;
                        }
                        if(vertices.at(i).getStateId()==toVertex){
                           
                            vertices.at(i).inDegree+=1;
                        }
                    }
                    cout<<"edge added sucessfully "<<endl;
                }
            }
            else{
                cout<<"invalid vertex id entered "<<endl;
            }
        }

        void printInDgree(Graph g){
            for(int i=0;i<vertices.size();i++){
        
                cout<<" the in degree of the vertex "<< vertices.at(i).getStateName()<<"is "<<vertices.at(i).inDegree<<endl;
                // cout<<" the out degree of the vertex "<< vertices.at(i).getStateName()<<"is"<<vertices.at(i).outDegree<<endl;

            }
        }
        void printOutDegree(Graph g){
            for(int i=0;i<vertices.size();i++){
            cout<<" the out degree of the vertex "<< vertices.at(i).getStateName()<<"is "<<vertices.at(i).outDegree<<endl;
            }
        }
        
        void printGraph() {
        for (int i = 0; i < vertices.size(); i++) {
        Vertex temp;
        temp = vertices.at(i);
        cout << temp.getStateName() << " (" << temp.getStateId() << ") --> ";
        temp.printEdgeList();
            }
        }

    void topoLogicalSort(Graph g){
        for(int i=0;i<vertices.size();i++){
            list<Edge> e;
            if(vertices.at(i).inDegree==0){
                topologicaArray.push_back(vertices.at(i).getStateName());
                cout<<"added to array "<<endl;
                cout<<topologicaArray.at(i)<<endl;
                
                
                e=vertices.at(i).getEdgeList();  

                for(auto it = e.begin(); it != e.end(); it++){  
                    cout<<"outerloop started"<<endl; 
                    for(int i=0;i<vertices.size();i++){
                        cout<<"innerloop started "<<endl;

                        if( (vertices.at(i).getStateId()) == (it->getDestinationVertexId())){
                            --(vertices.at(i).inDegree);
                            cout<<"indegree decremented"<<endl;
                                }
                            }
                            vertices.at(i).edgeList.clear();
                    }
                }
                else{
                    cout<<"the graph is cyclic"<<endl;
                }
            }
            
        }

        void printTopological(){
            for(int i=0;i<topologicaArray.size();i++){
                cout<<topologicaArray.at(i)<<endl;
            }
        }
  


        
    

};



int main()
{
    int option,id,id2,w;
    string name;
    Graph g;
    Vertex v1;

    do
    {
        cout<<"------------------------------------------------"<<endl;
        cout<<"select what operation you want to perform"<<endl;
        cout<<"-------------------------------------------------"<<endl;
        cout<<"0-to exit "<<endl;
        cout<<"1-addVertex()"<<endl;
        cout<<"2- addEdgeById() "<<endl;
        cout<<"3-printInDegree()"<<endl;
        cout<<"4-printOutDegree()"<<endl;
        cout<<"5-printGraph()"<<endl;
        cout<<"6-checktopological"<<endl;
        cout<<"7-printSort()"<<endl;



        cin>>option;

        switch (option)
        {

        case 1:
            cout<<"add vertex operation"<<endl;
            cout<<"enter state id "<<endl;
            cin>>id;

            cout<<"enter state name "<<endl;
            cin>>name;

            v1.setStateId(id);
            v1.setStateName(name);
            g.addVertex(v1);

            break;
        
        case 2:
            cout<<"add edge operation "<<endl;
            cout<<"enter id of source vertex(state)"<<endl;
            cin>>id;

            cout<<"enter id of destination vertex(state)"<<endl;
            cin>>id2;

            cout<<"enter weight "<<endl;
            cin>>w;
            g.addEdgeById(id,id2,w);
            break;

        case 3:
            g.printInDgree(g);
            break;

        case 4:
            g.printOutDegree(g);
            break;

        case 5:
            g.printGraph();
            break;

        case 6:
            g.topoLogicalSort(g);
            break;

        case 7:
            g.printTopological();
        default:
            break;
        }
    } while (option !=0);
    

    
    return 0;
}