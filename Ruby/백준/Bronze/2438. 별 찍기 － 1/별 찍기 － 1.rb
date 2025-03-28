a = gets.to_i
for i in 1..a
    for j in 1..i
        print "*"
    end
    print "\n"
=begin
이 부분이 좀 중요함. \n과 같은 특수문자는 double quote 쓰기. 또한 주석은 들여쓰기 불가.
=end
end 