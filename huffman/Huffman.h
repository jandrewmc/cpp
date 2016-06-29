#ifndef HUFFMAN_H
#define HUFFMAN_H

class Huffman
{
	public:
		Huffman();
		~Huffman();
		void initializeFromFile(string filename);
		void encode(string inputFilename, string outputfilename);
		void decode(string inputFilename, string outputfilename);

	private:	

}
