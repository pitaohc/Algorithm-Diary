impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let n = nums.len();
        let mut nums = nums;
        nums.sort();
        println!("sorted nums: {:?}", nums);
        let mut result: Vec<Vec<i32>> = vec![];
        // 枚举 a
        for first in 0..n {
            // 需要和上一次枚举的数不相同
            if first > 0 && nums[first] == nums[first - 1] {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            let mut third = n - 1;
            let target = -nums[first];
            // 枚举 b
            for second in first + 1..n {
                // 需要和上一次枚举的数不相同
                if second > first + 1 && nums[second] == nums[second - 1] {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while second < third && nums[second] + nums[third] > target {
                    third -= 1;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if second == third {
                    break;
                }
                if nums[second] + nums[third] == target {
                    result.push(vec![nums[first], nums[second], nums[third]]);
                }
            }
        }
        result
    }
}

struct Solution;

#[cfg(test)]
mod tests {
    use super::Solution;

    #[test]
    fn test() {
        let nums = vec![-1, 0, 1, 2, -1, -4];
        let res = vec![vec![-1, -1, 2], vec![-1, 0, 1]];
        assert_eq!(Solution::three_sum(nums), res);
    }

    #[test]
    fn test2() {
        let nums = vec![0, 1, 1];
        let res: Vec<Vec<i32>> = vec![];
        assert_eq!(Solution::three_sum(nums), res);
    }

    #[test]
    fn test3() {
        let nums = vec![0, 0, 0];
        let res = vec![vec![0, 0, 0]];
        assert_eq!(Solution::three_sum(nums), res);
    }
}

fn main() {
    println!("Hello, world!");
}
