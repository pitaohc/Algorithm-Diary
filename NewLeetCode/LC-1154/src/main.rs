//给你一个字符串 date ，按 YYYY-MM-DD 格式表示一个 现行公元纪年法 日期。返回该日期是当年的第几天。
//
//
//
// 示例 1：
//
//
//输入：date = "2019-01-09"
//输出：9
//解释：给定日期是2019年的第九天。
//
// 示例 2：
//
//
//输入：date = "2019-02-10"
//输出：41
//
//
//
//
// 提示：
//
//
// date.length == 10
// date[4] == date[7] == '-'，其他的 date[i] 都是数字
// date 表示的范围从 1900 年 1 月 1 日至 2019 年 12 月 31 日
//
//
// Related Topics 数学 字符串 👍 139 👎 0

struct Solution;

//leetcode submit region begin(Prohibit modification and deletion)
impl Solution {
    pub fn day_of_year(date: String) -> i32 {
        let year = date[0..4].parse::<i32>().unwrap();
        let month = date[5..7].parse::<i32>().unwrap();
        let day = date[8..10].parse::<i32>().unwrap();
        if year == 2023{
            println!("bye")
        }
        else if year == 2024{
            println!("hello")
        }

        //判断是否闰年
        let add_one = if year % 4 == 0 && year % 100 != 0 || year % 400 == 0 {
            1
        } else {
            0
        };

        let days_in_month = [31, 28 + add_one, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        let mut res = 0;
        for i in 0..month as usize - 1 {
            res += days_in_month[i];
        }
        res + day
    }
}
//leetcode submit region end(Prohibit modification and deletion)
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(Solution::day_of_year("2019-05-01".to_string()), 121);
        assert_eq!(Solution::day_of_year("2019-06-01".to_string()), 152);
        assert_eq!(Solution::day_of_year("2019-07-01".to_string()), 182);
        assert_eq!(Solution::day_of_year("2019-08-01".to_string()), 213);
        assert_eq!(Solution::day_of_year("2019-09-01".to_string()), 244);
        assert_eq!(Solution::day_of_year("2019-10-01".to_string()), 274);
        assert_eq!(Solution::day_of_year("2019-11-01".to_string()), 305);
        assert_eq!(Solution::day_of_year("2019-12-01".to_string()), 335);
    }

    #[test]
    fn test_2() {
        assert_eq!(Solution::day_of_year("2019-01-09".to_string()), 9);
        assert_eq!(Solution::day_of_year("2019-02-10".to_string()), 41);
        assert_eq!(Solution::day_of_year("2003-03-01".to_string()), 60);
        assert_eq!(Solution::day_of_year("2004-03-01".to_string()), 61);
        assert_eq!(Solution::day_of_year("1900-03-25".to_string()), 84);
        assert_eq!(Solution::day_of_year("2019-12-31".to_string()), 365);
        assert_eq!(Solution::day_of_year("2016-02-29".to_string()), 60);
        assert_eq!(Solution::day_of_year("2019-02-28".to_string()), 59);
        assert_eq!(Solution::day_of_year("2019-03-01".to_string()), 60);
        assert_eq!(Solution::day_of_year("2019-04-01".to_string()), 91);
    }
}


fn main() {
    println!("LC 1154");
}