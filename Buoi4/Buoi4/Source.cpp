#include <iostream>
#include <ctime>
using namespace std;

class StateBase
{
public:
	virtual StateBase* GetNextState() = 0;
	virtual char* ToString() = 0;
};

// State Locked
class Locked : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual char* ToString() {
		return (char*) "The door is locked";
	}
};

// State Closed
class Closed : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual char* ToString() {
		return (char*) "The door is closed";
	}
};

// State Opened
class Opened : public StateBase
{
public:
	virtual StateBase* GetNextState();
	virtual char* ToString() {
		return (char*) "The door is opened";
	}
};

StateBase * Locked::GetNextState()
{
	return new Closed();
}

StateBase * Closed::GetNextState()
{
	if (rand() % 2)
		return new Locked();
	return new Opened();
}

StateBase * Opened::GetNextState()
{
	return new Closed();
}

class CDoor
{
public:
	CDoor() {}
	CDoor(StateBase* pContext) {
		m_pState = pContext;
	}
	~CDoor() {
		delete m_pState;
	}
	void StateChanged() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState();
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}

private:
	StateBase* m_pState;
};

int main() {
	// initialize random seed
	srand(time(NULL));

	CDoor door(new Locked());
	cout << "Current state of the door: " << door.GetStateName() << endl;

	door.StateChanged();
	cout << "Current state of the door: " << door.GetStateName() << endl;

	door.StateChanged();
	cout << "Current state of the door: " << door.GetStateName() << endl;

	door.StateChanged();
	cout << "Current state of the door: " << door.GetStateName() << endl;

	door.StateChanged();
	cout << "Current state of the door: " << door.GetStateName() << endl;

	door.StateChanged();
	cout << "Current state of the door: " << door.GetStateName() << endl;

	door.StateChanged();
	cout << "Current state of the door: " << door.GetStateName() << endl;

	return 0;
}