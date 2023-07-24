/// @brief
class Edge
{
private:
    int v1;
    int v2;
    int weight;

public:
    Edge()
    {
        this->v1 = -1;
        this->v2 = -1;
        this->weight = -1;
    }
    Edge(int v1, int v2, int weight)
    {
        this->v1 = v1;
        this->v2 = v2;
        this->weight = weight;
    }

    int getSource(){
        return v1;
    }

    int getDestination(){
        return v2;
    }

    int getWeight(){
        return weight;
    }
};
