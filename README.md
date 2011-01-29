PNG Compressor
========================
Details of this project can be found on the [PNG Compressor page][2] under:  
[*http://www.CharmySoft.com/app/pngc.htm*][2]

Introduction
------------------------
[PNG Compressor][2] is a PNG image processing program used for compressing PNG files. It removes unnecessary PNG chunks, to loslessly reduce file size.


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
PNG Compressor can be obtained in many different ways. See details [here][3]:  
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
[2]: http://www.CharmySoft.com/app/pngc.htm "PNG Compressor"
[3]: http://www.CharmySoft.com/app/pngc.htm#download "Download PNG Compressor"
[4]: http://www.CharmySoft.com/about.htm "About CharmySoft"