# Test Process, Episode 22

### Timing:

- 00:00-00:45 intro
- 00:45-03:45 overview
- 03:45-10:45 astronomy lesson: the great galaxy debate
- 10:45-53:10 **simple techniques**
	- 16:40 stairstep tests
    - 24:40 assert first
    - 31:40 triangulation
	- 47:05 one to many
- 53:10-1:10:10 **refactoring tests**
	- 56:25 the two disks
- 1:10:10-1:15:10 **tests come first**
- 1:15:10-1:18:00 heresy
- 1:18:00-1:20:30 summary
- 1:20:30-1:22:50 ending credits

### Concepts:

- "Fake it 'til you make it" - make a test case pass by faking it, e.g., just returning 0 to test an edge case.
- Stairstep tests - tests whose sole purpose is to enable you to write the next step in sequence (usually delete when no longer needed)
- Assert first - write test backwards, starting with the assert; i.e., write the assert, then iteratively fix one error at a time by adding only the code needed to make that one error go away.
- Triangulation - adding a second specific test that will force you to modify the code you are currently testing to be more general (two tests + code being testeed = triangle); may lead to extracting an abstract class.
- One to many -
- Trap door function
- Golden rule of writing tests
- Test behavior, not APIs.
- Four rules of simple design:
