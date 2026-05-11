class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        tasks.sort(reverse=True)  # Optimization: fill larger tasks first to prune faster
        
        def can_assign(task_idx, sessions):
            # Base case: all tasks assigned
            if task_idx == len(tasks):
                return True
            
            task = tasks[task_idx]
            for i in range(len(sessions)):
                # If task fits in current session
                if sessions[i] + task <= sessionTime:
                    sessions[i] += task
                    if can_assign(task_idx + 1, sessions):
                        return True
                    # Backtrack
                    sessions[i] -= task
                
                # Pruning: If the current session is empty and we couldn't 
                # fit the task, trying other empty sessions won't help.
                if sessions[i] == 0:
                    break
            return False

        # Binary Search on the number of sessions
        low = 1
        high = len(tasks)
        ans = high
        
        while low <= high:
            mid = (low + high) // 2
            # Try to see if we can finish tasks using 'mid' sessions
            if can_assign(0, [0] * mid):
                ans = mid
                high = mid - 1  # Try fewer sessions
            else:
                low = mid + 1   # Need more sessions
                
        return ans