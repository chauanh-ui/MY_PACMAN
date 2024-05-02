#pragma once

/*
Common.h: khai báo những hàm dùng chung cho nhiều chỗ
	ok, có thừa cũng ko ảnh hưởng gì
	loadImage -> co the chuyen qua class Texture
	playSound -> class sound
	initSDL -> ok
	initframes -> nay ok 

Defs.h: khai báo những hằng, con số dùng cho nhiều chỗ 
*mảng chứa các kí tự để phân biệt các loại blocktype để ở đâu ???

Texture.h -> copy lazy foo
	render là quan trọng nhất
	render này có sẵn w, h, SDL_Texture* r, cần bỏ vào tọa độ x, y, clip-> cái src để nó còn crop ảnh, 
	góc để nó biết có cần xoay ảnh hay không

	==> đừng cái gì cũng nhét hết vào hàm khởi tạo pls -> hàm khởi tạo thì chỉ set những giá trị mặc định thôi chứ,
	// hàm khởi tạo bỏ nhiều nhất 2 cái para cho t
Sound.h -> copy 

Map.h: để làm gì, gọi khi nào // tạm thời bỏ qua

Entity// BaseObject: thôi gọi là Entity đi
Entity: sau Pacman và Ghost sẽ kế thừa con này
	texture: chứa texture của con entity này, sau nó còn gọi hàm render còn vẽ lên
	tọa độ x, y: dùng để truyền vào cho cái hàm render của con Texture để nó biết vị trí chỗ nào để nó còn vẽ
	không cần w, h: vì con texture có w, h r
	int entityType: thôi cứ thêm cho nó giống, đéo biết lúc nào mới dùng
	speed: tốc độ di chuyển, để cộng vào tọa độ x, y cho nó nhìn giống đang di chuyển, 
		chứ thực chất là thay đổi tọa độ x,y xong vẽ lại

	// tạm thời 2 cái này bỏ qua
	facing: đéo hiểu sao thằng này lại đặt là facing: ý là hướng mặt của nó hiện tại, chắc dùng để nhân với 90 độ,
	// trở thành cái góc cần bỏ vào hàm render để khi con pacman di chuyển nó quay mặt theo, chắc thể
	direction: đ hiểu khác facing chỗ nào, ý là hướng nó chuẩn bị di chuyển hay gì

	bool lifeStatement;
	bool turnAllows;

	void checkCollisonWithWalls; => update cái turnAllows để xem những hướng nào có thể đi được

	==> tóm lại hàm render chính là ở cái Texture class 


	PACMAN: ok đến con pacman, kế thừa con Entity
	ê thề nhiều lúc đ biết nên dùng con trỏ hay bỏ vào địa chỉ, cáu quá, thống nhất là bỏ vào con trỏ hết cho t
	có thêm 2 cái SDL_Rect clips[] --> khi nào dùng?? dùng khi render, khi nào gọi hàm 







*/




