#pragma once

#include "glIncludes.h" 
#include "vector"
#include "algorithm"
#include <stack>
class CCGRenderContext
{
public:
	CCGRenderContext();
	virtual ~CCGRenderContext();
	//实验1
	void drawPoints(void);
	void drawLines(void);
	void drawStrip(void);
	void drawLoop(void);
	void drawTriangles(void);
	void drawTriangle_Strip(void);
	void drawTriangle_Fan(void);
	void drawQuads(void);
	void drawQuad_Strip(void);
	void drawPolygon(void);
	void drawStar(void);
	//实验2
	void DDALine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color);
	void MidpointLine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color);
	void BresenhamLine(int xStart, int yStart, int xEnd, int yEnd, glm::vec3 color);
	void MidpointCircle(int centerX, int centerY, int radius, glm::vec3 color);
	void BresenhamCircle(int centerX, int centerY, int radius, glm::vec3 color);
	void DrawArc(int centerX, int centerY, int r, double start_angle, double end_angle, glm::vec3 color);
	void scanlineFill(std::vector<glm::ivec2>vtxs, glm::vec3 color);
	void scanlineFillTest();
	void BoundaryFill(int x, int y, glm::vec3 fill, glm::vec3 boundary);
	void FloodFill(int x, int y, glm::vec3 fill, glm::vec3 old);
};