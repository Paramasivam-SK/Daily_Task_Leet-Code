import leetcode
import pandas as pd
from datetime import datetime
import os

USERNAME = os.getenv("LEETCODE_USERNAME")
PASSWORD = os.getenv("LEETCODE_PASSWORD")
TRACKER_FILE = "progress.md"

# 1. Login to LeetCode
client = leetcode.Client()
client.login(USERNAME, PASSWORD)

# 2. Fetch recent submissions
submissions = client.get_recent_submissions(username=USERNAME)

# 3. Load existing tracker
if os.path.exists(TRACKER_FILE):
    with open(TRACKER_FILE, "r", encoding="utf-8") as f:
        lines = f.readlines()
else:
    lines = [
        "## 📈 Progress Tracker\n\n",
        "| Date       | Problem Title         | Difficulty | Status  |\n",
        "|------------|-----------------------|------------|---------|\n"
    ]

# 4. Extract already recorded titles to avoid duplicates
existing_titles = {line.split("|")[2].strip() for line in lines[3:] if "|" in line}

# 5. Append new problems
for sub in submissions:
    title = sub.title
    difficulty = sub.difficulty if hasattr(sub, "difficulty") else "Unknown"
    status = "✅ Done" if sub.statusDisplay == "Accepted" else "⏳ Pending"

    if title not in existing_titles:
        date_str = datetime.fromtimestamp(sub.timestamp).strftime("%Y-%m-%d")
        new_row = f"| {date_str} | {title} | {difficulty} | {status} |\n"
        lines.append(new_row)

# 6. Save updated tracker
with open(TRACKER_FILE, "w", encoding="utf-8") as f:
    f.writelines(lines)

print("✅ Tracker updated!")
