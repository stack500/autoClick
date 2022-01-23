class Clicker {
private:
	int cDelay;
	bool isRunning;
public:

	Clicker(); //Default Constructor
	Clicker(int delay); //Constructor
	~Clicker(); //Destructor

	//Function Declarations / Function Prototypes
	void startClick();
	void stopClick();
	void setDelay();


};