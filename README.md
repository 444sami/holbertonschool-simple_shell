<img src="https://i.postimg.cc/26vkFX6d/Holberton-Shell.jpg" width="1050" height="120">

<a href="https://github.com/444sami"> <strong>Samara González</strong>, </a>
<a href="https://github.com/Pablo-Laborde"> <strong>Pablo Laborde</strong> </a>

 <h2>
        <strong>Description</strong>
</h2>
<p>hsh (Holberton SHell) is a command interpreter, a program that takes commands from the standard input, a file or a command line string, and gives them to the operating system to perform.</p>

<h2><strong> Instalation </strong></h2>
<p>
* Clone the repository <pre><code> git clone https://github.com/Pablo-Laborde/holbertonschool-simple_shell.git </code></pre>
* Compile <pre><code> gcc *.c -o hsh </code></pre>
</p>
<h2> <strong> Usage </strong> </h2>
<h3> Non-Interactive Mode </h3>
<p>
* <pre><code> echo "command" | ./hsh </code></pre>
* <pre><code> cat "filename" | ./hsh </code></pre>
</p>
<h3> Interactive Mode </h3>
<p>
* <pre><code> ./hsh </code></pre>
</p>

<h2>
        <strong>Requirements</strong>
</h2>
<p>This project has the following requirements:

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)</p>
<h2>
        <strong>Compilation</strong>
</h2>
<p>The shell will be compiled this way:

<code>gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh</code></p>
<h2>
        <strong>Testing</strong>
</h2>
<p>The shell works like this in interactive mode:

<pre><code>$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$</code></pre></p>
<p>But also in non-interactive mode:

<pre><code>$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$</code></pre></p>
 <h2>
        <strong>Flowchart</strong>
</h2>
<p><img src="https://i.postimg.cc/k45ZS19S/Shell-Flowchart.jpg" width="784" height="872"></p>
 <h2>
        <strong>List of files</strong>
 </h2>
 <p>Files we created for this project:

* Documentation: README.md, man_1_simple_shell, AUTHORS.
* Shell: _simple_shell.c
* Auxiliar functions: </p>
<hr>
Samara González, Pablo Laborde. Cohort 20.
