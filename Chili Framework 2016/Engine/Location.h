#pragma once
struct Location {	//struct is different from class b/c struct defaults everything to public (struct is also for very simple data types)
	void Add(const Location& val) {
		x += val.x;
		y += val.y;
	}
	int x;
	int y;
};