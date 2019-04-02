#!/usr/bin/env ruby
#
# chkptr.rb
# Copyright (C) 2019 Shewer Lu <shewer@gmail.com>
#
# Distributed under terms of the MIT license.
#
Flag= "__CHK#{ARGV.shift}__"
puts ARGV
puts ENV["HOME"]
fn="chkptr"

pfile="/tmp/#{fn}.c"
ml=ARGV.map { |cmd|    "\t_Eval( #{cmd},\"\" );"}.join("\n")
head= <<EOF
#define #{Flag}
#include "point.h"

int main(int argc , char * argv[]) 
{
\tchar ch,*ptr;
#{ml}
\treturn 0;
}
EOF
File.write(pfile, head)
ccprog='gcc '
libs=["point"]

gccflag=" -L. -L#{ENV["HOME"]}/.local/lib -I#{ENV["HOME"]}/.local/include -ldl -o /tmp/#{fn} "
cmd = ccprog + pfile 
cmd +=  libs.map(&" -l".method(:+)).join(" ")
cmd += gccflag

puts head
puts cmd 
flag= system(cmd)
retcode=$?
puts flag,"---------------------------------------------" 
if flag
  exec("/tmp/#{fn}")
else
  STDERR.puts "compile ERROR(#{$?}  #{retcode}): cmd"


