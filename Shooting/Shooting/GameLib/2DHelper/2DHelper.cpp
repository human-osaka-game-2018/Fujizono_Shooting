#include "2DHelper.h"

Helper2D::Helper2D()
{
}

Helper2D::~Helper2D()
{
}

//中心点から横幅縦幅を使って、矩形を作る関数
void Helper2D::SetVerticesFromCenterType(Simple2DVertex* vertices, float posCenterX, float posCenterY, float posWidthFromCenter, float posHeightFromCenter, float rightTU, float bottomTV, float leftTU, float topTV)
{
	vertices[0] = { posCenterX - posWidthFromCenter,  posCenterY - posHeightFromCenter, 0.0f, 1.0f, 0xffffffff,  leftTU,    topTV };
	vertices[1] = { posCenterX + posWidthFromCenter,  posCenterY - posHeightFromCenter, 0.0f, 1.0f, 0xffffffff, rightTU,    topTV };
	vertices[2] = { posCenterX + posWidthFromCenter,  posCenterY + posHeightFromCenter, 0.0f, 1.0f, 0xffffffff, rightTU, bottomTV };
	vertices[3] = { posCenterX - posWidthFromCenter,  posCenterY + posHeightFromCenter, 0.0f, 1.0f, 0xffffffff,  leftTU, bottomTV };
}

//左上頂点から横幅縦幅を使って、矩形を作る関数
void Helper2D::SetVerticesFromLeftTopType(Simple2DVertex* vertices, float posLeftTopX, float posLeftTopY, float rectWidth, float rectHeight, float rightTU, float bottomTV, float leftTU, float topTV)
{
	vertices[0] = { posLeftTopX            ,  posLeftTopY             , 0.0f, 1.0f, 0xffffffff,  leftTU,    topTV };
	vertices[1] = { posLeftTopX + rectWidth,  posLeftTopY             , 0.0f, 1.0f, 0xffffffff, rightTU,    topTV };
	vertices[2] = { posLeftTopX + rectWidth,  posLeftTopY + rectHeight, 0.0f, 1.0f, 0xffffffff, rightTU, bottomTV };
	vertices[3] = { posLeftTopX            ,  posLeftTopY + rectHeight, 0.0f, 1.0f, 0xffffffff,  leftTU, bottomTV };
}

//左上頂点中心タイプの矩形の、頂点座標だけセットする関数
void Helper2D::SetVerticesFromLeftTopType(Simple2DVertex* vertices, float posLeftTopX, float posLeftTopY)
{
	//移動する量を計算で出す
	float movementX = vertices[0].x - posLeftTopX;
	float movementY = vertices[0].y - posLeftTopY;

	//登録されている頂点座標を移動させる
	vertices[0].x = vertices[0].x - movementX;
	vertices[0].y = vertices[0].y - movementY;

	vertices[1].x = vertices[1].x - movementX;
	vertices[1].y = vertices[1].y - movementY;

	vertices[2].x = vertices[2].x - movementX;
	vertices[2].y = vertices[2].y - movementY;

	vertices[3].x = vertices[3].x - movementX;
	vertices[3].y = vertices[3].y - movementY;
}


//矩形の色情報を変える関数
void Helper2D::SetVerticesColor(Simple2DVertex* vertices, DWORD color)
{
	vertices[0].color = color;
	vertices[1].color = color;
	vertices[2].color = color;
	vertices[3].color = color;
}

//1頂点の色情報を変える関数
void Helper2D::SetVertexColor(Simple2DVertex* vertices, DWORD color)
{
	vertices->color = color;
}
