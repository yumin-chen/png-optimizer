<img src="http://raw.github.com/CharmySoft/png-optimizer/master/icon/png-optimizer-icon.png" width="48"/>&nbsp;&nbsp;**PNG Optimizer**
========================
Details of this project can be found on the [PNG Optimizer page][2] under:  
[*http://www.CharmySoft.com/app/pngc.htm*][2]

Introduction
------------------------
[PNG Optimizer][2] is a PNG image processing program used for compressing PNG files. It removes unnecessary PNG chunks, to loslessly reduce file size.
For demonstration purpose, a pre-compiled version is included in the [exe folder](/exe) where you can find some executable files that can run on different platforms.


Instruction
------------------------
To use this code, compile it on Linux with this command:  

	g++ src/pngc.cpp -o pngc 

Then run the executable with  

	./pngc


Usage
------------------------
Use the following command line to compress PNG files:  

	pngc [files...]  

(On some operating systems this can be done by a drag and drop operation)  

Warning: this will remove all unnecessary chunks. Backup before use.  
After compression, only the following chunks will be left:  

 * IHDR  
 * IDAT  
 * PLTE  
 * tRNS   
 * IEND  

Any other chunks will be removed. This can losslessly reduce the PNG file size.

For more information about PNG chunks, read [PNG Specification, Version 1.2](http://www.libpng.org/pub/png/spec/1.2/PNG-Chunks.html).


Downloading
------------------------
PNG Optimizer can be obtained in many different ways. See details [here][3]:  
[*http://www.CharmySoft.com/app/pngc.htm#download*][3]


Licensing
------------------------
Please see the file named [LICENSE](LICENSE).


Author
------------------------
* Charlie Chen  
	founder of [CharmySoft][1]


Contact
------------------------
* CharmySoft: [*http://www.CharmySoft.com/*][1]  
* About: [*http://www.CharmySoft.com/about.htm*][4]  

[1]: http://www.CharmySoft.com/ "CharmySoft"
[2]: http://www.CharmySoft.com/app/pngc.htm "PNG Optimizer"
[3]: http://www.CharmySoft.com/app/pngc.htm#download "Download PNG Optimizer"
[4]: http://www.CharmySoft.com/about.htm "About CharmySoft"