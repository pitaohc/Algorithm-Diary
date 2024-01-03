impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let thousands = Vec::from(["", "M", "MM", "MMM"]);
        let hundreds = Vec::from(["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]);
        let tens = Vec::from(["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]);
        let ones = Vec::from(["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]);
        let mut result: String = String::new();
        let num: usize = num as usize;
        result.push_str(thousands[num / 1000]);
        result.push_str(hundreds[num % 1000 / 100]);
        result.push_str(tens[num % 100 / 10]);
        result.push_str(ones[num % 10]);
        result
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn test3() {
        assert_eq!(Solution::int_to_roman(3), "III".to_string());
    }

    #[test]
    fn test3999() {
        let num = 3999;
        let ans = "MMMCMXCIX";
        assert_eq!(Solution::int_to_roman(num), ans.to_string());
    }
}

fn main() {
    println!("Hello, world!");
}
