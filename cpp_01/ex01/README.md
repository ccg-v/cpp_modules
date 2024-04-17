<h1>Exercise 01: Moar Brainz!</h1>

<h2>Target</h2>
<p>Learn how to allocate an array of objects and initialize them all.</p>

<h2>Subject</h2>
<p>Time to create a horde of Zombies!</p>
<p>Implement the following function in the appropriate file:</p>
<pre><code>   Zombie*    zombieHorde( int N, std::string name );</pre></code>
<p>It must allocate N Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.</p>
<p>Implement your own tests to ensure your zombieHorde() function works as expected. Try to call announce() for each one of the zombies.</p>
<p>Don’t forget to delete all the zombies and check for memory leaks.</p>

<h2>Pseudocode flow chart</h2>
<p align="center">
	<img src="assets/cpp01_ex01.png" />
</p>