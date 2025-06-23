class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Алгоритимческая сложность O(n)
        // Сложность по памяти O(1)
        int max_profit {0};

        for (std::size_t index {0}; index < std::size(prices) - 1; ++index) {
            int current_price {prices[index]};
            int next_price {prices[index + 1]};

            if ( next_price > current_price ) {
                int differnt_price = next_price - current_price;
                max_profit += differnt_price;
            }
        }
        return max_profit; 
    }
};