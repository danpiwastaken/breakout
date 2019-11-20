#include "GameState.h"




// Input: tham so dang con tro tiny_state
// Output:
// Chuc nang: set state
void GameState::setState(tiny_state* state)
{
	// neu _state khac NULL, chay ham Destroy voi tham so _window
	if (this->_state != NULL)
	{
		this->_state->Destroy(this->_window);
	}

	this->_state = state; // gan _state bang tham so truyen vao

	// neu _state khac NULL, chay ham Initialize voi tham so _window
	if (this->_state != NULL)
	{
		this->_state->Initialize(this->_window);
	}
} 

// Input:
// Output:
// Chuc nang: cap nhat state
void GameState::Update()
{
	// neu _state khac NULL, chay ham Update voi tham so _window
	if (this->_state != NULL)
	{
		this->_state->Update(this->_window);
	}
}

// Input:
// Output:
// Chuc nang: ve~ state
void GameState::Render()
{
	// neu _state khac NULL, chay ham Render voi tham so _window
	if (this->_state != NULL)
	{
		this->_state->Render(this->_window);
	}
}

// Input:
// Output: doi thuong GameState
// Chuc nang: khoi tao GameState
GameState::GameState()
{
	this->_state = NULL; // gan _state la NULL
}

// Input:
// Output: 
// Chuc nang: giai phong bo nho
GameState::~GameState()
{
	// neu _state khac NULL, chay ham Destroy voi tham so _window
	if (this->_state != NULL)
	{
		this->_state->Destroy(this->_window);
	}
}
