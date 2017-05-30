`/home/stw/s/joel.wallin/encore/release/encorec test.enc`
ok = 0
not_ok = 0
n = 200
n.times do
  result = `./test --ponythreads=2`
  if result == "1\n2\n"
    ok += 1
  else
    not_ok += 1
    puts result
    puts "---------------------------------------------"
  end
end
print "OK:     #{ok}\nNOT OK: #{not_ok}\n"
