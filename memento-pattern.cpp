#include <iostream>
using namespace std;

class Memento {
private:
	string text;
public:
	Memento (const string& t) : text(t) {}
	string getText() const {
		return text;
	}
};
class TextBox {
private:
	string currentText;
public: 
	void SetText(const string& t) {
		currentText = t;
		cout << "Textbox set to:" << currentText << endl;
	}
	Memento save() const {
		return Memento(currentText);
	}
	void restore(const Memento& m) {
		currentText = m.getText();
		cout << "Textbox restored to: " << currentText << endl;
	}
};
int main() {
	TextBox textbox;
	Memento snapshot(""); // перший порожній знімок//
	textbox.SetText("Hello");
	snapshot = textbox.save();
	textbox.SetText("world");
	textbox.restore(snapshot);
	return(0);
}
