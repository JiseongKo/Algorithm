# [Platinum III] Rooks - 8103 

[문제 링크](https://www.acmicpc.net/problem/8103) 

### 성능 요약

메모리: 2316 KB, 시간: 0 ms

### 분류

자료 구조, 그리디 알고리즘, 우선순위 큐

### 제출 일자

2024년 10월 10일 18:49:37

### 문제 설명

<p>On the chessboard of size n × n (1 ≤ n ≤ 3,000) we put n rooks. The arrangement of the rooks should satisfy the following rules:</p>

<ul>
	<li>For each i = 1, ..., n, the i-th rook can be put on the rectangle specified by two pairs of coordinates: (a<sub>i</sub>, b<sub>i</sub>), (c<sub>i</sub>, d<sub>i</sub>), where (a<sub>i</sub>, b<sub>i</sub>) are coordinates of the square in the left upper corner of the rectangle (row, column), (c<sub>i</sub>, d<sub>i</sub>) are coordinates of the square in the right lower corner of the rectangle, 1 ≤ a<sub>i</sub> ≤ c<sub>i</sub> ≤ n and 1 ≤ b<sub>i</sub> ≤ d<sub>i</sub> ≤ n. A field in the left upper square has coordinates (1, 1), a square in the right lower corner has coordinates (n, n).</li>
	<li>No two rooks can attack each other, i.e. they cannot stay in the same row or the same column.</li>
</ul>

<p>Write a program which:</p>

<ul>
	<li>reads from the standard input the size of the rectangle n and for each i = 1, ..., n the coordinates of the rectangle, in which the i-th rook can be put,</li>
	<li>verifies, whether the rooks may be put in appropriate rectangles so that no two of them attack each other, and if so, finds one of such arrangements,</li>
	<li>writes into the standard output one arrangement of the rooks satisfying given conditions or single word <code>NIE</code> (which means “no” in Polish) if such an arrangement doesn't exists.</li>
</ul>

### 입력 

 <p>In the first line of the standard input there is written one positive integer n, 1 ≤ n ≤ 3,000. In each of the following n lines there are written four positive integers not greater than n separated by single spaces. The numbers in the i-th line are the coordinates of the rectangle, in which the i-th rook may be put (a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub> and d<sub>i</sub> respectively).</p>

### 출력 

 <p>In the standard output there should be written one word <code>NIE</code>, or in each of n lines of the output file there should be written two integers separated by a single space. The numbers in the i-th line should denote the position of i-th rook (row, column). This position should be within the rectangle specified by coordinates in the (i+1)-th line of the input. Pay attention to the fact that the positions of the rooks should be written in the same order as the coordinates of the rectangles were read from the input.</p>

