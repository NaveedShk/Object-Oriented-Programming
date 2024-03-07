#include <iostream> 
using namespace std;

class Square{
    private:
    float side_length;
    float area;
    static float total_areas;
    public:
    Square() {
        side_length = 0;
        area = 0;
    }
    Square(float length){
        this->side_length = length;
        area = 0;
    }
    void set_length(float length){
        this->side_length = length;
    }
    void set_area(float area){
        this->area = area;
    }
    void set_total_areas(float total_areas){
        this->total_areas = total_areas;
    }
    float get_length(){
        return side_length;
    }
    float get_area(){
        return area;
    }
    float get_total_areas(){
        return total_areas;
    }
    void calculate_area(){
        area = side_length * side_length;
        total_areas += area;
    }
};
float Square::total_areas = 0;

int main(){
    cout << "Name: Sheikh Naveed Azeemi \nRoll no: 23K-0003\n" << endl;
    
    Square square1(6); 
    square1.calculate_area(); 
    cout << "Area of the square = " << square1.get_area() << endl;
    cout << "The total area of all squares is = " << square1.get_total_areas() << endl;

    Square square2;

    float side;
    cout << "\nEnter the side length for the square: ";
    cin >> side;
    square2.set_length(side);
    square2.calculate_area();
    cout << "Area of this square is equal to " << square2.get_area() << endl;

    cout << "\nThe total area of all the squares is = " << square2.get_total_areas() << endl;
}
