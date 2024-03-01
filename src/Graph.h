#pragma once
class Graph {
private:

public:
	virtual void Move(const float& dx, const float& dy);
	//virtual void rotate(const float& rad);
	virtual void Show() const;
	virtual void SetAlpha(const int alpha);
	virtual void Clr() const;
};