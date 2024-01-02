impl Solution {
    fn get_range(start: i32, end: i32) -> String {
        if start == end {
            return start.to_string();
        }
        return format!("{}->{}", start, end);
    }
    pub fn summary_ranges(nums: Vec<i32>) -> Vec<String> {
        if nums.len() == 0 {
            return Vec::new();
        }
        let mut result: Vec<String> = Vec::new();
        let mut start: i32 = 0;
        let mut end: i32 = 0;
        for i in 0..nums.len() {
            if i == 0 {
                start = nums[i];
                end = nums[i];
            } else if nums[i] == end + 1 {
                end = nums[i];
            } else {
                result.push(Solution::get_range(start, end));
                start = nums[i];
                end = nums[i];
            }
        }
        result.push(Solution::get_range(start, end));
        result
    }
}

struct Solution;

#[cfg(test)]
mod tests{
    use super::Solution;
    #[test]
    fn test() {
        let nums: Vec<i32> = vec![0, 1, 2, 4, 5, 7];
        let result: Vec<String> = vec!["0->2".to_string(), "4->5".to_string(), "7".to_string()];
        assert_eq!(Solution::summary_ranges(nums), result);
    }

    #[test]
    fn test2() {
        let nums: Vec<i32> = vec![0, 2, 3, 4, 6, 8, 9];
        let result: Vec<String> = vec!["0".to_string(), "2->4".to_string(), "6".to_string(), "8->9".to_string()];
        assert_eq!(Solution::summary_ranges(nums), result);
    }
    #[test]
    fn test_empty() {
        let nums: Vec<i32> = Vec::new();
        let result: Vec<String> = Vec::new();
        assert_eq!(Solution::summary_ranges(nums), result);
    }
}
fn main() {
    println!("Hello, world!");
}
