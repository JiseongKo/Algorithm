# [Platinum V] Huge Knight - 9717 

[문제 링크](https://www.acmicpc.net/problem/9717) 

### 성능 요약

메모리: 2496 KB, 시간: 0 ms

### 분류

애드 혹, 너비 우선 탐색, 자료 구조, 그래프 이론, 그래프 탐색, 해시를 사용한 집합과 맵, 트리를 사용한 집합과 맵

### 제출 일자

2024년 10월 11일 15:31:01

### 문제 설명

<p>You have a chessboard of size N x N. The rows and columns are numbered from 1 to N. In a cell located at row R1 and column C1, a knight is starting his journey. The knight wants to go to the cell located at row R2 and column C2. Move the knight from the starting cell to this destination cell with minimum number of moves.  </p>

<p>As a reminder, a knight's jump moves him 2 cells along one of the axes, and 1 cell along the other one. In other words, if a knight is at (A,B), it may move to (A‐2,B ‐1), (A‐2, B+1), (A+2, B‐1), (A+2, B+1), (A‐1, B‐2), (A+1,B‐2), (A‐1, B+2) or (A+1, B+2).  Of course, the knight cannot leave the board.</p>

<p>Given N, R1, C1, R2 and C2, determine the minimum number of steps necessary to move the knight from (R1, C1) to (R2, C2).  </p>

### 입력 

 <p>The first input line contains a positive integer,T, indicating the number of test cases.  Each case consists of a line containing five integers N(3≤N≤10<sup>15</sup>), R1, C1, R2 and  are between 1 and N inclusive.  </p>

### 출력 

 <p>For each test case, output the minimum number of steps needed to move the knight from (R1, C1) to (R2, C2). Assume that there will always be a solution, i.e., it’s possible to move the knight from its starting cell to its destination cell.  </p>

