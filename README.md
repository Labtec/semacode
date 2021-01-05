# Ruby Semacode Encoder

## Introduction

This Ruby extension implements a DataMatrix encoder for Ruby. It is typically
used to create semacodes, which are barcodes, that contain URLs. This encoder
does not create image files or visual representations of the semacode. This is
because it can be used for more than creating images, such as rendering
semacodes to HTML, SVG, PDF or even stored in a database or file for later
use.

See test.rb for an example of how to create a visual symbol for a semacode, it
presents a semacode in HTML and plain text formats, and this can give you an
idea of how to start.

Once you have a visual representation of the semacode, you can use a reader,
such as those from https://semacode.com on your camera phone, to capture the
URL embedded in the semacode and proceed directly to that web site.

### License

This software is released under the terms of the GNU Public License version 2,
available from https://www.gnu.org.

### Contact Information

You can contact me via guido@sohne.net if you have patches, bug fixes or
improvements.

  Copyright (C) 2007, Guido Sohne
  Website: http://sohne.net/projects/semafox

### Credits

Based on the iec16022ecc200.c encoder by Adrian Kennard, Andrews & Arnold Ltd.

## Quick Start

Configure the extension to your local system and ruby:

    ruby extconf.rb

Build the extension:

    make

Test that it works:

    ruby test.rb

Install the extension (you may need to become root):

    make install

You should take a look at `tests/test.rb` to understand how to use this. It
includes some code to generate a semacode using HTML and CSS, so that could
end up being useful.


## Usage

Here are some basic ways in which you can make use of this extension. It tries
to show by example, how the semacodes can be created and what can be done with
or to a semacode object.

Include this library:

    require 'rubygems'
    require 'semacode'

Create a semacode:

    semacode = Barcode::Semacode.new 'http://sohne.net/projects/semafox/'

Return the semacode as an array of boolean arrays.

The first element of the array is the top row, the last element is the bottom
row. the array length is the semacode height, and each element is an array as
wide as the semacode width:

    grid = semacode.data

or

    grid = semacode.to_a

Return the encoding list used to create the semacode.

This encoding list is composed of the 'character set', complete with shifts
from one encoding type to another, that is used for the DataMatrix algorithm:

    encoding = semacode.encoding

Return the semacode as a string.

The string is a comma separated list of character vectors. Each vector is a row
in the semacode symbol, the top row is first, and the bottom row is last.
Inside each row, the vector reads from left to right:

    semacode.to_s

or

    semacode.to_str

Encode another string:

    semacode.encode 'http://sohne.net'

Get the width of the semacode:

    semacode.width

Get the height of the semacode:

    semacode.height

How long is the semacode? (width * height)

    semacode.length

or

    semacode.size

Get the raw encoded length (before padding and before ECC):

    semacode.raw_encoded_length

Get the symbol size. The max number of characters this semacode type (specific
width x height) can hold is called the symbol size:

    semacode.symbol_size

Count the ECC bytes. How many bytes were used for error correction?

    semacode.ecc_bytes

## Notes

The C code can throw runtime exceptions. Be sure to include a catch block if
you want to use this in production. Mostly the exceptions are not recoverable,
except for when the data is too long, in which case you can shorten it and try
again.

There are two type of exceptions that it will throw. The first is a
`RangeError` exception, which happens when the input is too long or when it
just can't find a fit for the data. The second is an `ArgumentError` exception
that gets thrown when the input contains data it cannot handle.
