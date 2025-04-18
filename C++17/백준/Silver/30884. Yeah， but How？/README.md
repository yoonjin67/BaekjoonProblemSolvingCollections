# [Silver III] Yeah, but How? - 30884 

[문제 링크](https://www.acmicpc.net/problem/30884) 

### 성능 요약

메모리: 3180 KB, 시간: 8 ms

### 분류

애드 혹, 해 구성하기

### 제출 일자

2024년 11월 17일 19:57:50

### 문제 설명

<p><span style="color:#e74c3c;"><code>(</code></span>와 <span style="color:#e74c3c;"><code>)</code></span>로만 이루어진 문자열 $S$가 아래 조건을 충족하면, 이를 <strong>균형 잡힌 괄호 문자열</strong>이라고 한다.</p>

<ul>
	<li>$S$에 <span style="color:#e74c3c;"><code>1</code></span>과 <span style="color:#e74c3c;"><code>+</code></span>를 원하는 위치에 적절히 추가해서 제대로 된 수식을 만들 수 있다.

	<ul>
		<li>예로, <span style="color:#e74c3c;"><code>(()())</code></span>는 $((1+1)+(1)+1)$ 등의 수식을 만들 수 있으므로 균형 잡힌 괄호 문자열이다.</li>
		<li>하지만, <span style="color:#e74c3c;"><code>())(</code></span>는 <span style="color:#e74c3c;"><code>1</code></span>과 <span style="color:#e74c3c;"><code>+</code></span>를 어떻게 넣어도 제대로 된 수식을 만들어 낼 수 없으므로 균형 잡힌 괄호 문자열이 아니다.</li>
	</ul>
	</li>
</ul>

<p>여기서, <strong>제대로 된 수식</strong>은 다음과 같이 정의된다.</p>

<ul>
	<li>$1$은 제대로 된 수식이다.</li>
	<li>$T_1$과 $T_2$가 제대로 된 수식이라면, 두 수식을 더하는 $T_1+T_2$도 제대로 된 수식이다.</li>
	<li>$T$가 제대로 된 수식이라면, 수식에 괄호를 씌운 $(T)$도 제대로 된 수식이다.</li>
</ul>

<p>세훈이는 이 정의에 궁금증을 가지고, 균형 잡힌 괄호 문자열이 주어질 때 수식을 직접 만들어 보기로 했다.</p>

### 입력 

 <p>첫 번째 줄에 균형 잡힌 괄호 문자열 $S$가 주어진다. $(2\le\lvert S\rvert\le 200\, 000)$</p>

### 출력 

 <p>첫 번째 줄에 주어진 괄호 문자열로 만들 수 있는 수식 $T$를 출력한다.출력되는 수식 $T$는 다음 조건을 충족해야 한다.</p>

<ul>
	<li>수식의 길이는 $500\, 000$ 이하여야 한다.</li>
	<li>$T$는 제대로 된 수식이어야 한다.</li>
	<li>$T$에서 <span style="color:#e74c3c;"><code>(</code></span>와 <span style="color:#e74c3c;"><code>)</code></span>만 남기면 $S$가 만들어져야 한다.</li>
	<li>$T$는 <span style="color:#e74c3c;"><code>(</code></span>, <span style="color:#e74c3c;"><code>)</code></span>, <span style="color:#e74c3c;"><code>1</code></span>, <span style="color:#e74c3c;"><code>+</code></span>로만 이루어져야 한다. <strong>특히, 수식의 중간에 공백 등의 문자가 들어가면 안 된다.</strong></li>
</ul>

<p>입력 조건 내에서, 위 조건을 충족하는 수식을 만들 수 있음을 증명할 수 있다.</p>

<p>가능한 수식이 여러 가지인 경우, 그중 아무거나 하나를 출력한다.</p>

