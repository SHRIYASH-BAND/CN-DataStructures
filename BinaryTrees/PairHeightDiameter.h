template <typename T>
class PairHeightDiameter
{
public:
    T height;
    T diameter;
    PairHeightDiameter()
    {
        height = 0;
        diameter = 0;
    }
    PairHeightDiameter(T h, T d)
    {
        height = h;
        diameter = d;
    }
};