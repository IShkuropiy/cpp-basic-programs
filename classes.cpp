#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

 
enum Color {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    BLUE = 34
};

const float DEFAULT_INK_VOLUME = 20.0;
const float INK_VOLUME_PER_CHAR = 1.0;


//BASE CLASS 1
class Pen {
    private:
        Color color;

    protected:
        float inkVolume;
        virtual void writeChar(char ch);

    public:
        Pen(); // constructors
        Pen(Color c);

        virtual void write(string text);
        bool canUse();

        Color getColor(); // getter of private value
};
// BASE CLASS 2
class Pencil {
    private: 
        string type; // praphit charcoal colored 
        string hardness; // for graphite: h hb b f
        int sharpness;// 0 to 10 (0 - dull, 10 - sharp)
        int dullRate; // chars per sharpness point

        void setDullRate() {
            if(hardness == "H") dullRate = 20;
            else if (hardness == "HB") dullRate =15;
            else if (hardness == "F") dullRate = 10;
            else if (hardness == "B") dullRate = 5;
            else dullRate = 10; // default
        }
        public: 

        Pencil(string t, string h, int s) : type(t), hardness(h), sharpness(s) {
        setDullRate();
}

    void isSharpen() {
        sharpness = 10;
        cout << "Pencil is mint and dont need to be sharpened.\n"; 
    }

    void draw(string text) {
        int chars = text.length();
        int usage = (chars + dullRate - 1) / dullRate;

        if (usage > sharpness) {
            cout << "You need to sharpen your pencil. \n";
            return;
        }

        sharpness -= usage; 
        cout << " You wrote: " << text << endl;
        cout << "Sharpness now: " << sharpness << "/10";
        cout << endl;
    }

    int getSharpness() const {
        return sharpness;
    };
};


// CHILD
class CapsPen : public Pen {
    protected:
        void writeChar(char ch) override;

    public:
        CapsPen() : Pen() {};
        CapsPen(Color c) : Pen(c) {};
};
// GRANDCHILD
class SpacedPen : public CapsPen {
        public:
           SpacedPen() : CapsPen() {}
           SpacedPen(Color c) : CapsPen(c) {}
           void write(string text) override;
};

// PEN
Pen::Pen() {
    color = Color::BLACK;
    inkVolume = DEFAULT_INK_VOLUME;
}

Pen::Pen(Color c) {
    color = c;
    inkVolume = DEFAULT_INK_VOLUME;
}

Color Pen::getColor() {
    return color;
}

void Pen::writeChar(char ch) {
    cout << "\033[1;" << color << "m" << ch << "\033[0m";
}

void Pen::write(string text) {
    for (int i = 0; i < text.length(); i++) {
        if (text[i] != ' ') {
            inkVolume = inkVolume - INK_VOLUME_PER_CHAR;
            if (inkVolume < 0.0) {
                cout << ' ';            
                continue;
            }
        }
        writeChar(text[i]);
    }
    cout << "<END>\n";
}

bool Pen::canUse()
{
    return inkVolume > 0.0;
}
// CAPSPEN
void CapsPen::writeChar(char ch) {
    cout << "\033[1;" << getColor() << "m" << (char)toupper(ch) << "\033[0m";
}
// SPACEDPEN 
void SpacedPen::write(string text) {
    for (char c : text) {
        if (c != ' ') {
            // use base class's inkVolume (inherited)
            inkVolume = inkVolume - INK_VOLUME_PER_CHAR;
            if (inkVolume < 0.0) {
                cout << "  "; // double space for missing ink
                continue;
            }
        }
        writeChar(c);
        cout << ' '; // spacing between letters
    }
    cout << "<END>\n";
}


int main() {
    Pen pen1(Color::RED);
    if (pen1.canUse()) {
        pen1.write("Hello, my name is Ira, and I learn programming, heheheh");
    }

    Pen pen2(Color::BLUE);
    if (pen2.canUse()) {
        pen2.write("This is blue, and we're full of color in this text");
    }

    CapsPen pen3(Color::GREEN);
    if (pen3.canUse()) {
        pen3.write("This is green, and we're full of color in this text");
    }

    SpacedPen pen4(Color::RED);
    if (pen4.canUse()) {
        pen4.write("This is red and spaced and we wanna see the results");
    }

    Pencil myPencil("graphite", "B", 10);

    myPencil.draw("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam");
    cout << "Current sharpness: " << myPencil.getSharpness() << endl;

    myPencil.draw("Another one? Let's try.");
    myPencil.isSharpen();
    myPencil.draw("Fresh again!");

    return 0;
    // Pen *pen3 = new Pen(Color::BLUE);
    // delete pen3;
}