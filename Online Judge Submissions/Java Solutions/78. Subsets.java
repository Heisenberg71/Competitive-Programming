class Solution {
    List<List<Integer>> powerSet;
    void generatePowerSet(int index, List<Integer> currentSet, int[] nums) {
        if(index == nums.length) {
            powerSet.add(new ArrayList<>(currentSet));
            return;
        }
        currentSet.add(nums[index]);
        generatePowerSet(index + 1, currentSet, nums);
        currentSet.removeLast();
        generatePowerSet(index + 1, currentSet, nums);
    }
    
    public List<List<Integer>> subsets(int[] nums) {
        powerSet = new ArrayList<>();
        generatePowerSet(0, new ArrayList<>(), nums);
        return powerSet;
    }
}
